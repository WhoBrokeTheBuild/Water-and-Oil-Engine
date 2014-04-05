#ifndef WOE_GL_GRAPHICS_SYSTEM_H
#define WOE_GL_GRAPHICS_SYSTEM_H

#include "BaseGraphicsSystem.h"

class GLGraphicsSystem :
	public BaseGraphicsSystem
{
public:

	GLGraphicsSystem( int width, int height, string title );

	virtual ~GLGraphicsSystem( void );

protected:

};

#endif // WOE_GL_GRAPHICS_SYSTEM_H