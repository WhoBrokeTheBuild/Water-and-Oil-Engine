#ifndef WOE_GL_GRAPHICS_SYSTEM_H
#define WOE_GL_GRAPHICS_SYSTEM_H

#include "BaseGraphicsSystem.h"

class GLGraphicsSystem :
	public BaseGraphicsSystem
{
public:

	GLGraphicsSystem( int width, int height, string title );

	virtual ~GLGraphicsSystem( void );

	virtual inline string getClassName( void ) const { return "GL Graphics System"; }

	virtual void beginRender( void );
	virtual void endRender( void );

protected:

	virtual void doResizeWindow( void );

};

#endif // WOE_GL_GRAPHICS_SYSTEM_H