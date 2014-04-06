#ifndef WOE_GL_GRAPHICS_SYSTEM_H
#define WOE_GL_GRAPHICS_SYSTEM_H

#if defined(_WOE_WINDOWS)

#	define NOGDI

#	define WIN32_LEAN_AND_MEAN
#	include <Windows.h>

#endif // _WOE_WINDOWS

#if defined(_WOE_OPENGL)

#include "BaseGraphicsSystem.h"

#include "Log.h"

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>

void glfwError( int error, const char* description );

void glfwResize( GLFWwindow* window, int width, int height );

void glfwKey( GLFWwindow* window, int key, int scancode, int action, int mods );

void glfwMouseMove( GLFWwindow* window, double x, double y );

void glfwMouse( GLFWwindow* window, int button, int action, int mods );

void glfwMouseScroll( GLFWwindow* window, double x, double y );

class GLGraphicsSystem :
	public BaseGraphicsSystem
{
public:

	GLGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen = false );

	virtual ~GLGraphicsSystem( void );

	virtual inline string getClassName( void ) const { return "GL Graphics System"; }

#pragma region Properties

	virtual void setClearColor( const Color& clearColor );

#pragma endregion Properties

	virtual void update( const GameTime* pGameTime );

	virtual void beginRender( void );
	virtual void endRender( void );

#pragma region Hooks

	virtual void hookWindowResized( int width, int height );

#pragma endregion Hooks

protected:

	virtual void doResizeWindow( const int& width, const int& height );
	virtual void doChangeFullscreen( const bool& fullscreen );
	virtual void doChangeWindowTitle( const string& title );

	GLFWwindow*			mp_GLFWWindow;

};

#endif // _WOE_OPENGL

#endif // WOE_GL_GRAPHICS_SYSTEM_H