#ifndef WOE_ARGS_H
#define WOE_ARGS_H

#if defined(_WOE_DIRECTX)

#define NOGDI
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef struct WIN32Args
{
public:

	inline WIN32Args( HINSTANCE instance, HINSTANCE prevInstance, LPWSTR cmdLine, int numCmdShow )
		: m_Instance(instance),
		  m_PrevInstance(prevInstance),
		  m_CmdLine(cmdLine),
		  m_NumCmdShow(numCmdShow)
	{ }

	inline WIN32Args( const WIN32Args& rhs )
		: m_Instance(rhs.m_Instance),
		  m_PrevInstance(rhs.m_PrevInstance),
		  m_CmdLine(rhs.m_CmdLine),
		  m_NumCmdShow(rhs.m_NumCmdShow)
	{ }

	inline HINSTANCE getInstance( void ) const { return m_Instance; }
	inline HINSTANCE getPrevInstance( void ) const { return m_PrevInstance; }

	inline LPWSTR getCmdLine( void ) const { return m_CmdLine; }
	inline int getNumCmdShow( void ) const { return m_NumCmdShow; }

protected:

	HINSTANCE		m_Instance,
					m_PrevInstance;

	LPWSTR			m_CmdLine;

	int				m_NumCmdShow;

} WIN32Args;

typedef WIN32Args Args;

#elif defined(_WOE_OPENGL)

typedef struct STDArgs
{
public:

	inline STDArgs( int argc, char** argv )
		: m_Argc(argc),
		  mp_Argv(argv)
	{ }

	inline STDArgs( const STDArgs& rhs )
		: m_Argc(rhs.m_Argc),
		  mp_Argv(rhs.mp_Argv)
	{ }

	inline int getArgc( void ) const { return m_Argc; }
	inline char** getArgv( void ) const { return mp_Argv; }

protected:

	unsigned int m_Argc;
	char** mp_Argv;

} STDArgs;

typedef STDArgs Args;

#endif

#endif // WOE_ARGS_H