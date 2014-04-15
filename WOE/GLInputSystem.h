#ifndef WOE_GL_INPUT_SYSTEM_H
#define WOE_GL_INPUT_SYSTEM_H

#include "BaseInputSystem.h"

#if defined(_WOE_OPENGL)

#include "GLHeader.h"
#include "Key.h"
#include "MouseButton.h"
#include "ScrollWheelDir.h"

class GameTime;

class GLInputSystem
	: public BaseInputSystem
{
public:

	GLInputSystem( void );

	~GLInputSystem( void );

	virtual inline string getClassName( void ) const { return "GL Input System"; }

	virtual void update(  const GameTime* pGameTime );

#pragma region Hooks

	void hookKeyDown( Key key );
	void hookKeyUp( Key key );
	void hookMouseButtonDown( MouseButton button );
	void hookMouseButtonUp( MouseButton button );
	void hookWheelScroll( ScrollWheelDir scrollDir );
	void hookMouseMoved( float x, float y );

#pragma endregion Hooks

protected:



};

void glfwKey( GLFWwindow* window, int key, int scancode, int action, int mods );

void glfwMouseMove( GLFWwindow* window, double x, double y );

void glfwMouse( GLFWwindow* window, int button, int action, int mods );

void glfwMouseScroll( GLFWwindow* window, double x, double y );

#endif // _WOE_OPENGL

#endif // WOE_GL_INPUT_SYSTEM_H