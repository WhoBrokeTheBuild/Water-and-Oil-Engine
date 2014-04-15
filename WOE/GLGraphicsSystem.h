#ifndef WOE_GL_GRAPHICS_SYSTEM_H
#define WOE_GL_GRAPHICS_SYSTEM_H

#if defined(_WOE_OPENGL)

#include "BaseGraphicsSystem.h"

#include "GLHeader.h"

class GLInputSystem;

class GLGraphicsSystem :
	public BaseGraphicsSystem
{

	friend class GLInputSystem;

public:

	GLGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen = false );

	virtual ~GLGraphicsSystem( void );

	virtual inline string getClassName( void ) const { return "GL Graphics System"; }

	virtual void setClearColor( const Color& clearColor );

	virtual void update( const GameTime* pGameTime );

	virtual void beginRender( void );
	virtual void endRender( void );

	virtual void hookWindowResized( int width, int height );

protected:

	GLFWwindow*	getGLFWWindow( void ) { return mp_GLFWWindow; }

	virtual void doResizeWindow( const int& width, const int& height );
	virtual void doChangeFullscreen( const bool& fullscreen );
	virtual void doChangeWindowTitle( const string& title );
	void processGLFWEvents(void);
	GLFWwindow*			mp_GLFWWindow;

};

void glfwError( int error, const char* description );

void glfwResize( GLFWwindow* window, int width, int height );

#endif // _WOE_OPENGL

#endif // WOE_GL_GRAPHICS_SYSTEM_H