#ifndef WOE_TIMER_H
#define WOE_TIMER_H

#include <Arc/ManagedObject.h>

#include <ctime>
#include <cmath>

#if defined(_WOE_WINDOWS)

#define NOGDI

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#elif defined(_WOE_LINUX)

#include <sys/time.h>
#include <unistd.h>

#endif

using Arc::ManagedObject;

class Timer :
    public ManagedObject
{
public:

    Timer( void );
	virtual inline ~Timer( void ) { }

    virtual inline string getClassName( void ) const { return "Timer"; }

    void start( void );

    void stop ( void );

    double getElapsedMilli( void );

    double getElapsedSeconds( void );

	void sleepUntilElapsed( double millis );

private:

	static double		MICRO;

	double				m_StartTimeMillis,
						m_EndTimeMillis;

	bool				m_Stopped;

#if defined(_WOE_WINDOWS)

	LARGE_INTEGER		m_Freq,
						m_StartCount,
						m_EndCount;

	inline double calcDiffMillis( LARGE_INTEGER from, LARGE_INTEGER to ) const
	{
		return (double)(to.QuadPart - from.QuadPart) * (MICRO / m_Freq.QuadPart) * 0.001;
	}

#elif defined(_WOE_LINUX)

	timeval				m_StartCount, 
						m_EndCount;

	inline double calcDiffMillis( timeval from, timeval to ) const
	{
		return (double)( ((to.tv_sec - from.tv_sec) * 1000.0) + ((to.tv_usec - from.tv_usec) / 1000.0) );
	}

#endif

};

#endif // WOE_TIMER_H
