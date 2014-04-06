#include "GLGraphicsSystem.h"

#if defined(_WOE_OPENGL)

#include "GameTime.h"
#include "Game.h"
#include "GLRenderTarget.h"

GLGraphicsSystem::GLGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen /* = false */ )
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

	mp_RenderTarget = New GLRenderTarget();
}

GLGraphicsSystem::~GLGraphicsSystem(void)
{
	delete mp_RenderTarget;
}

void GLGraphicsSystem::setClearColor( const Color& clearColor )
{
	BaseGraphicsSystem::setClearColor(clearColor);

	glClearColor(clearColor.getFloatR(), clearColor.getFloatG(), clearColor.getFloatB(), clearColor.getFloatA());
}

void GLGraphicsSystem::update( const GameTime* pGameTime )
{
	glfwPollEvents();

	if (glfwWindowShouldClose(mp_GLFWWindow))
	{
		dispatchEvent(Event(Game::EVENT_EXIT));
	}
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

void GLGraphicsSystem::doResizeWindow( const int& width, const int& height )
{
	glfwSetWindowSize(mp_GLFWWindow, width, height);
}

void GLGraphicsSystem::doChangeFullscreen( const bool& fullscreen )
{
	// UNDONE
}

void GLGraphicsSystem::doChangeWindowTitle( const string& title )
{
	glfwSetWindowTitle(mp_GLFWWindow, title.c_str());
}

void GLGraphicsSystem::hookWindowResized(int width, int height)
{
	m_Width = width;
	m_Height = height;
	dispatchEvent(Event(EVENT_WINDOW_RESIZED));
}

void glfwError( int error, const char* description )
{
	Log::ErrorFmt("GLFW", "%s (code %d)", description, error);
}

void glfwResize( GLFWwindow* window, int width, int height )
{
	Game::Instance()->getGraphicsSystem()->hookWindowResized(width, height);
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

#endif // _WOE_OPENGL