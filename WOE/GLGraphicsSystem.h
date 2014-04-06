#ifndef WOE_GL_GRAPHICS_SYSTEM_H
#define WOE_GL_GRAPHICS_SYSTEM_H

#define NOGDI

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

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

	GLGraphicsSystem( int width, int height, string title, bool fullscreen = false );

	virtual ~GLGraphicsSystem( void );

	virtual inline string getClassName( void ) const { return "GL Graphics System"; }

	virtual void update( const GameTime* pGameTime );

	virtual void beginRender( void );
	virtual void endRender( void );

protected:

	virtual void doResizeWindow( void );

	GLFWwindow*			mp_GLFWWindow;

};

#endif // WOE_GL_GRAPHICS_SYSTEM_H