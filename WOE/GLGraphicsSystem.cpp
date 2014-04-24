#include "GLGraphicsSystem.h"

#if defined(_WOE_OPENGL)

#include "Log.h"
#include "GameTime.h"
#include "Game.h"
#include "GLRenderTarget.h"
#include "GLInputSystem.h"

#include <sstream>

using std::stringstream;

GLGraphicsSystem::GLGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen /* = false */ )
	: BaseGraphicsSystem(width, height, title, fullscreen)
{
	Log::Info(getClassName(), "Starting Up");

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

	stringstream ss;
	ss << title.c_str() << " - OpenGL";

	mp_GLFWWindow = glfwCreateWindow(m_Width, m_Height, ss.str().c_str(), NULL, NULL);

	if ( ! mp_GLFWWindow )
	{
		Log::Error("Main", "Failed to open GLFW window");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(mp_GLFWWindow);

	glfwSwapInterval(0);

	glfwSetFramebufferSizeCallback(mp_GLFWWindow, glfwResize);

	glewExperimental = GL_TRUE;
	GLenum ret = glewInit();
	if (ret != GLEW_OK)
	{
		Log::ErrorFmt(getClassName(), "Failed to initialize GLEW (Error #%d, %s)", ret, glewGetErrorString(ret));
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	mp_RenderTarget = New RenderTarget();
	mp_ShaderManager = New ShaderManager();

	Log::Info(getClassName(), "Finished");
}

GLGraphicsSystem::~GLGraphicsSystem(void)
{
	Log::Info(getClassName(), "Shutting Down");

	delete mp_ShaderManager;
	delete mp_RenderTarget;

	glfwDestroyWindow(mp_GLFWWindow);
	glfwTerminate();

	Log::Info(getClassName(), "Finished");
}

void GLGraphicsSystem::setClearColor( const Color& clearColor )
{
	BaseGraphicsSystem::setClearColor(clearColor);

	glClearColor(clearColor.getFloatR(), clearColor.getFloatG(), clearColor.getFloatB(), clearColor.getFloatA());
}

void GLGraphicsSystem::update( const GameTime* pGameTime )
{
	processGLFWEvents();
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

void GLGraphicsSystem::processGLFWEvents( void )
{
	glfwPollEvents();

	if (glfwWindowShouldClose(mp_GLFWWindow))
	{
		Game::Instance()->dispatchEvent(Event(Game::EVENT_EXIT));
	}
}

void glfwError( int error, const char* description )
{
	Log::ErrorFmt("GLFW", "%s (code %d)", description, error);
}

void glfwResize( GLFWwindow* window, int width, int height )
{
	Game::Instance()->getGraphicsSystem()->hookWindowResized(width, height);
}

#endif // _WOE_OPENGL