#ifndef WOE_BASE_GRAPHICS_SYSTEM_H
#define WOE_BASE_GRAPHICS_SYSTEM_H

#include <Arc/ManagedObject.h>
#include <string>

class RenderTarget;
class GameTime;

using Arc::ManagedObject;
using std::string;

class BaseGraphicsSystem :
	public ManagedObject
{
public:

	inline BaseGraphicsSystem( int width, int height, string title, bool fullscreen = false )
		: m_Width(width), 
		  m_Height(height),
		  m_Title(title),
		  m_Fullscreen(fullscreen)
	{ }

	virtual inline ~BaseGraphicsSystem( void ) { }

#pragma region Properties

	inline string getTitle( void ) const { return m_Title; }
	inline void   setTitle( string title ) { m_Title = title; }

	inline int getWidth ( void ) const { return m_Width; }
	inline int getHeight( void ) const { return m_Height; }

	inline void setWidth ( int width )  { resizeWindow(width, m_Height); }
	inline void setHeight( int height ) { resizeWindow(m_Width, height); }

	inline bool isFullscreen( void ) const { return m_Fullscreen; }
	inline void setFullscreen( bool fullscreen ) { m_Fullscreen = fullscreen; }
	inline bool toggleFullscreen( void ) { m_Fullscreen = ! m_Fullscreen; return m_Fullscreen; }

#pragma endregion Properties

	inline void resizeWindow( int width, int height ) 
	{
		m_Width = width;
		m_Height = height;

		doResizeWindow();
	}
	
	virtual void update( const GameTime* pGameTime ) = 0;

	virtual void beginRender( void ) = 0;
	virtual void endRender  ( void ) = 0;

protected:

	BaseGraphicsSystem( void );
	BaseGraphicsSystem( const BaseGraphicsSystem& rhs );

	virtual void doResizeWindow( void ) = 0;

	string			m_Title;

	int				m_Width, m_Height;

	RenderTarget*	mp_RenderTarget;

	bool			m_Fullscreen;

};

#endif // WOE_BASE_GRAPHICS_SYSTEM_H