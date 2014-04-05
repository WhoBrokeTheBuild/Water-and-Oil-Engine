#ifndef WOE_GAME_H
#define WOE_GAME_H

#include <Arc/ManagedObject.h>

#include "GraphicsSystem.h"
//#include "AudioSystem.h"

using Arc::ManagedObject;

class Game :
	public ManagedObject
{
public:

	static Game* Instance( void );

	static void Destroy( void );

	virtual inline string getClassName( void ) const { return "Game"; }

	void start( void );

private:

	Game( void );
	virtual ~Game( void );

	static Game*		s_Instance;

	GraphicsSystem*		mp_GraphicsSystem;

};

#endif // WOE_GAME_H