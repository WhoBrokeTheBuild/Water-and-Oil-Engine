#include "GLInputSystem.h"

#if defined(_WOE_OPENGL)

#include "Log.h"
#include "Game.h"
#include "GLInputFunc.h"
#include "GameTime.h"

GLInputSystem::GLInputSystem( void )
	: BaseInputSystem()
{
	Log::Info(getClassName(), "Starting Up");

	GLFWwindow* pGLFWWindow = Game::Instance()->getGraphicsSystem()->getGLFWWindow();

	glfwSetKeyCallback(pGLFWWindow, glfwKey);
	glfwSetMouseButtonCallback(pGLFWWindow, glfwMouse);
	glfwSetCursorPosCallback(pGLFWWindow, glfwMouseMove);
	glfwSetScrollCallback(pGLFWWindow, glfwMouseScroll);

	Log::Info(getClassName(), "Finished");
}

GLInputSystem::~GLInputSystem( void )
{
	Log::Info(getClassName(), "Shutting Down");


	Log::Info(getClassName(), "Finished");
}

void GLInputSystem::update( const GameTime* pGameTime )
{
	auto end = m_Keys.itEnd();
	for (auto it = m_Keys.itBegin(); it != end; ++it)
	{
		InputInfo* pInfo = &it->second;

		if (pInfo->State == InputState::WOE_INPUT_STATE_DOWN)
		{
			pInfo->HoldTime += pGameTime->getDeltaMS();
		}
	}
}

void GLInputSystem::hookKeyDown( Key key )
{
	m_Keys[key].PressCount++;
	m_Keys[key].State = InputState::WOE_INPUT_STATE_DOWN;
	m_Keys[key].LastPressTime = Game::Instance()->getGameTime()->getTotalElapsedMS();
}

void GLInputSystem::hookKeyUp( Key key )
{
	m_Keys[key].State = InputState::WOE_INPUT_STATE_UP;
	m_Keys[key].HoldTime = 0.0f;
}

void GLInputSystem::hookMouseButtonDown( MouseButton button )
{

}

void GLInputSystem::hookMouseButtonUp( MouseButton button )
{

}

void GLInputSystem::hookWheelScroll( ScrollWheelDir scrollDir )
{

}

void GLInputSystem::hookMouseMoved( float x, float y )
{
	m_DeltaMouseX = x - m_MouseX;
	m_DeltaMouseY = y - m_MouseY;

	m_MouseX = x;
	m_MouseY = y;
}

void glfwKey( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	switch (action)
	{
	case GLFW_PRESS:

		Game::Instance()->getInputSystem()->hookKeyDown(convertKeyGLFW(key));

		break;
	case GLFW_RELEASE:

		Game::Instance()->getInputSystem()->hookKeyUp(convertKeyGLFW(key));

		break;
	}
}

void glfwMouseMove( GLFWwindow* window, double x, double y )
{
	Game::Instance()->getInputSystem()->hookMouseMoved((float)x, (float)y);
}

void glfwMouse( GLFWwindow* window, int button, int action, int mods )
{
	switch (action)
	{
	case GLFW_PRESS:

		Game::Instance()->getInputSystem()->hookMouseButtonDown(convertMouseButtonGLFW(button));

		break;
	case GLFW_RELEASE:

		Game::Instance()->getInputSystem()->hookMouseButtonUp(convertMouseButtonGLFW(button));

		break;
	}
}

void glfwMouseScroll( GLFWwindow* window, double x, double y )
{
	if (x != 0.0)
	{
		ScrollWheelDir xDir = ( x > 0.0 ? WOE_SCROLL_WHEEL_DIR_RIGHT : WOE_SCROLL_WHEEL_DIR_LEFT );
		Game::Instance()->getInputSystem()->hookWheelScroll(xDir);
	}

	if (y != 0.0)
	{
		ScrollWheelDir yDir = ( y > 0.0 ? WOE_SCROLL_WHEEL_DIR_UP : WOE_SCROLL_WHEEL_DIR_DOWN );
		Game::Instance()->getInputSystem()->hookWheelScroll(yDir);
	}
}

#endif // _WOE_OPENGL