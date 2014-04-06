#ifndef WOE_DX_GRAPHICS_SYSTEM_H
#define WOE_DX_GRAPHICS_SYSTEM_H

#include "BaseGraphicsSystem.h"

class GameTime;

class DXGraphicsSystem :
	public BaseGraphicsSystem
{
public:

	DXGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen = false );

	virtual ~DXGraphicsSystem( void );

	virtual inline string getClassName( void ) const { return "DX Graphics System"; }

	virtual void update( const GameTime* pGameTime );

	virtual void beginRender( void );
	virtual void endRender( void );

protected:

	virtual void doResizeWindow(const int& width, const int& height);

	virtual void doChangeFullscreen(const bool& fullscreen);

	virtual void doChangeWindowTitle(const string& title);

};

#endif // WOE_DX_GRAPHICS_SYSTEM_H