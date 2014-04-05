#ifndef WOE_DX_GRAPHICS_SYSTEM_H
#define WOE_DX_GRAPHICS_SYSTEM_H

#include "BaseGraphicsSystem.h"

class DXGraphicsSystem :
	public BaseGraphicsSystem
{
public:

	DXGraphicsSystem( int width, int height, string title, bool fullscreen = false );

	virtual ~DXGraphicsSystem( void );

	virtual inline string getClassName( void ) const { return "DX Graphics System"; }

	virtual void beginRender( void );
	virtual void endRender( void );

protected:

	virtual void doResizeWindow( void );

};

#endif // WOE_DX_GRAPHICS_SYSTEM_H