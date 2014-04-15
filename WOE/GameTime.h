#ifndef WOE_GAME_TIME_H
#define WOE_GAME_TIME_H

#include <Arc/ManagedObject.h>

using Arc::ManagedObject;

class GameTime :
	public ManagedObject
{
public:

	inline GameTime( void )
		: m_TargetFPS(),
		  m_CurrentFPS(),
		  m_CurrentFPSPercent(), 
		  m_TotalElapsedMS(), 
		  m_DeltaMS(), 
		  m_DeltaMod(),
		  m_FrameDelayMS()
	{ }

	virtual inline ~GameTime( void ) { }

	virtual inline string getClassName( void ) const { return "Game Time"; }

	virtual inline void updateTime( double deltaMS )
	{
		if (deltaMS <= 0.0)
			return;

		m_DeltaMS = deltaMS;
		m_TotalElapsedMS += deltaMS;

		m_DeltaMod = m_FrameDelayMS / m_DeltaMS;

		m_CurrentFPSPercent = m_DeltaMS / m_FrameDelayMS;
		m_CurrentFPS = m_TargetFPS * m_CurrentFPSPercent;
	}

#pragma region Properties

	inline double getTotalElapsedMS( void ) const { return m_TotalElapsedMS; }
	inline double getDeltaMS( void ) const { return m_DeltaMS; }
	inline double getDeltaMod( void ) const { return m_DeltaMod; }

	inline double getCurrentFPS( void ) const { return m_CurrentFPS; }
	inline double getCurrentFPSPercent( void ) const { return m_CurrentFPSPercent; }

	inline double getTargetFPS( void ) const { return m_TargetFPS; }
	inline void setTargetFPS( double targetFPS ) 
	{
		if (targetFPS <= 0.0)
		{
			m_TargetFPS = -1.0;
			m_FrameDelayMS = 0.0;
			return;
		}

		m_TargetFPS = targetFPS;
		m_FrameDelayMS = 1000.0 / m_TargetFPS;
	}

	inline double getFrameDelayMS( void ) const { return m_FrameDelayMS; }

#pragma endregion Properties

protected:

	double		m_TargetFPS, 
				m_CurrentFPS, 
				m_CurrentFPSPercent, 
				m_TotalElapsedMS, 
				m_DeltaMS, 
				m_DeltaMod, 
				m_FrameDelayMS;

};

#endif // WOE_GAME_TIME_H