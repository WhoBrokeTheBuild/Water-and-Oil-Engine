#include "GLGraphicsSystem.h"

#include "GameTime.h"

GLGraphicsSystem::GLGraphicsSystem( int width, int height, string title, bool fullscreen /* = false */ )
	: BaseGraphicsSystem(width, height, title, fullscreen)
{
	if ( ! glfwInit())
	{
		Log::Error("Main", "Failed to initialize GLFW");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_DEPTH_BITS, 16);

	GLFWmonitor* pMonitor = glfwGetPrimaryMonitor();

	if (m_Fullscreen)
	{
		const GLFWvidmode* mode = glfwGetVideoMode(pMonitor);

		if (mode->width > 0 && mode->height > 0)
		{
			m_Width = mode->width;
			m_Height = mode->height;
		}
	}

	mp_GLFWWindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);

	if ( ! mp_GLFWWindow )
	{
		Log::Error("Main", "Failed to open GLFW window");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(mp_GLFWWindow);

	glfwSwapInterval(0);

	glfwSetFramebufferSizeCallback(mp_GLFWWindow, glfwResize);
	glfwSetKeyCallback(mp_GLFWWindow, glfwKey);
	glfwSetMouseButtonCallback(mp_GLFWWindow, glfwMouse);
	glfwSetCursorPosCallback(mp_GLFWWindow, glfwMouseMove);
	glfwSetScrollCallback(mp_GLFWWindow, glfwMouseScroll);
}

GLGraphicsSystem::~GLGraphicsSystem(void)
{
}

void GLGraphicsSystem::update( const GameTime* pGameTime )
{
	glfwPollEvents();
}

void GLGraphicsSystem::beginRender( void )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glClearDepth(1.0f);
}

void GLGraphicsSystem::endRender( void )
{
	glfwSwapBuffers(mp_GLFWWindow);
}

void GLGraphicsSystem::doResizeWindow( void )
{
}

void glfwError( int error, const char* description )
{
	Log::ErrorFmt("GLFW", "%s (code %d)", description, error);
}

void glfwResize( GLFWwindow* window, int width, int height )
{

}

void glfwKey( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	switch (action)
	{
	}
}

void glfwMouseMove( GLFWwindow* window, double x, double y )
{

}

void glfwMouse( GLFWwindow* window, int button, int action, int mods )
{
	switch (action)
	{
	}
}

void glfwMouseScroll( GLFWwindow* window, double x, double y )
{

}
