#ifndef WOE_GAME_H
#define WOE_GAME_H

#include "EventDispatcher.h"

#include "GraphicsSystem.h"

class GameTime;

class Game :
	public EventDispatcher
{
public:

	static const EventType		EVENT_UPDATE,
								EVENT_RENDER,
								EVENT_EXIT;

	static Game* Instance( void );

	static void Destroy( void );

	virtual inline string getClassName( void ) const { return "Game"; }

	inline GraphicsSystem* getGraphicsSystem( void ) { return mp_GraphicsSystem; }

	inline GameTime* getGameTime( void ) { return mp_GameTime; }

	void start( void );

	void update( void );
	void render( void );

#pragma region Event Handlers

	inline void evtExit( const Event& event )
	{
		m_Running = false;
	}

#pragma endregion Event Handlers

private:

	Game( void );
	virtual ~Game( void );

	static Game*		s_Instance;

	GraphicsSystem*		mp_GraphicsSystem;
	
	bool				m_Running;
	
	GameTime*			mp_GameTime;

};

#endif // WOE_GAME_H