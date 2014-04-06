#include "Timer.h"

double Timer::MICRO = 1000000.0;

Timer::Timer( void )
{
#	if defined(_WOE_WINDOWS)

    QueryPerformanceFrequency(&m_Freq);
    m_StartCount.QuadPart = 0;
    m_EndCount.QuadPart   = 0;

#	elif defined(_WOE_LINUX)

	m_StartCount.tv_sec = 0;
	m_StartCount.tv_usec = 0;
    m_EndCount.tv_sec = 0;
    m_EndCount.tv_usec = 0;

#	endif

    m_Stopped = false;
    m_StartTimeMillis = 0;
    m_EndTimeMillis   = 0;
}

void Timer::start( void )
{
    m_Stopped = false;

#	if defined(_WOE_WINDOWS)

		QueryPerformanceCounter(&m_StartCount);

#	elif defined(_WOE_LINUX)

		gettimeofday(&m_StartCount, nullptr);

#	endif
}

void Timer::stop( void )
{
    m_Stopped = true;

#if defined(_WOE_WINDOWS)

		QueryPerformanceCounter(&m_EndCount);

#	elif defined(_WOE_LINUX)

		gettimeofday(&m_EndCount, nullptr);

#	endif
}

double Timer::getElapsedMilli( void )
{
#if defined(_WOE_WINDOWS)

		if ( ! m_Stopped)
			QueryPerformanceCounter(&m_EndCount);

		m_StartTimeMillis = (m_StartCount.QuadPart * (MICRO / m_Freq.QuadPart)) * 0.001;
		m_EndTimeMillis   = (m_EndCount.QuadPart * (MICRO / m_Freq.QuadPart)) * 0.001;

#	elif defined(_WOE_LINUX)

		if ( ! m_Stopped)
			gettimeofday(&m_EndCount, nullptr);

		m_StartTimeMillis = ((m_StartCount.tv_sec * MICRO) + m_StartCount.tv_usec) * 0.001;
		m_EndTimeMillis   = ((m_EndCount.tv_sec * MICRO) + m_EndCount.tv_usec) * 0.001;

#	endif

    return m_EndTimeMillis - m_StartTimeMillis;
}

double Timer::getElapsedSeconds( void )
{
    return getElapsedMilli() / 1000.0;
}

void Timer::sleepUntilElapsed( double millis )
{
    double timeToSleep;

#if defined(_WOE_WINDOWS)

		LARGE_INTEGER currentTime, lastTime;

		QueryPerformanceCounter(&currentTime);
		timeToSleep = millis - calcDiffMillis(m_StartCount, currentTime);

#	elif defined(_WOE_LINUX)

		timeval currentTime, lastTime;

		gettimeofday(&currentTime, nullptr);
		timeToSleep = millis - calcDiffMillis(m_StartCount, currentTime);

#	endif

#	if defined(_WOE_WINDOWS)

		timeToSleep = max(0.0, timeToSleep);

#	elif defined(_WOE_LINUX)

		timeToSleep = std::max(0.0, timeToSleep);

#	endif

    while (timeToSleep > 0.0)
    {
        double timeElapsed;
        lastTime = currentTime;

#		if defined(_WOE_WINDOWS)

			QueryPerformanceCounter(&currentTime);
			timeElapsed = calcDiffMillis(lastTime, currentTime);

#		elif defined(_WOE_LINUX)

			gettimeofday(&currentTime, nullptr);
			timeElapsed = calcDiffMillis(lastTime, currentTime);

#		endif

        timeToSleep -= timeElapsed;

        if( timeToSleep > 10.0 )
		{
#			if defined(_WOE_WINDOWS)

				// Sleep for 10 milliseconds per loop
				Sleep(10);

#			elif defined(_WOE_LINUX)

				// Sleep for 10 milliseconds per loop
				usleep(10 * 1000);

#			endif
        }
    }
}
