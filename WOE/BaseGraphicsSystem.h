#ifndef WOE_BASE_GRAPHICS_SYSTEM_H
#define WOE_BASE_GRAPHICS_SYSTEM_H

#include "EventDispatcher.h"

#include <string>

#include "Color.h"
#include "RenderTarget.h"

class GameTime;

using std::string;

class BaseGraphicsSystem :
	public EventDispatcher
{
public:

	static const EventType		EVENT_WINDOW_RESIZED,
								EVENT_FULLSCREEN_CHANGED,
								EVENT_WINDOW_TITLE_CHANGED,
								EVENT_CLEAR_COLOR_CHANGED;

	inline BaseGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen = false )
		: m_Width(width), 
		  m_Height(height),
		  m_Title(title),
		  m_Fullscreen(fullscreen)
	{ }

	virtual inline ~BaseGraphicsSystem( void ) { }

#pragma region Properties

	virtual inline string getTitle( void ) const { return m_Title; }
	virtual inline void   setTitle( const string& title )
	{
		m_Title = title;
		dispatchEvent(Event(EVENT_WINDOW_TITLE_CHANGED));
	}

	virtual inline int getWidth ( void ) const { return m_Width; }
	virtual inline int getHeight( void ) const { return m_Height; }

	virtual inline void setWidth ( const int& width )  { resizeWindow(width, m_Height); }
	virtual inline void setHeight( const int& height ) { resizeWindow(m_Width, height); }

	virtual inline bool isFullscreen( void ) const { return m_Fullscreen; }
	virtual inline void setFullscreen( const bool& fullscreen ) 
	{
		m_Fullscreen = fullscreen;
		dispatchEvent(Event(EVENT_FULLSCREEN_CHANGED));
	}

	virtual inline bool toggleFullscreen( void )
	{
		m_Fullscreen = ! m_Fullscreen;
		dispatchEvent(Event(EVENT_FULLSCREEN_CHANGED));
		return m_Fullscreen;
	}

	virtual inline Color getClearColor( void ) const { return m_ClearColor; }
	virtual inline void  setClearColor( const Color& clearColor ) { m_ClearColor = clearColor; }

#pragma endregion Properties
	
	virtual inline void resizeWindow( const int& width, const int& height ) 
	{
		m_Width = width;
		m_Height = height;

		dispatchEvent(Event(EVENT_WINDOW_RESIZED));
	}
	
	virtual void update( const GameTime* pGameTime ) = 0;

	virtual void beginRender( void ) = 0;
	virtual void endRender  ( void ) = 0;

protected:

	BaseGraphicsSystem( void );
	BaseGraphicsSystem( const BaseGraphicsSystem& rhs );

	virtual void doResizeWindow( const int& width, const int& height ) = 0;
	virtual void doChangeFullscreen( const bool& fullscreen ) = 0;
	virtual void doChangeWindowTitle( const string& title ) = 0;

	string			m_Title;

	int				m_Width, m_Height;

	RenderTarget*	mp_RenderTarget;

	bool			m_Fullscreen;

	Color			m_ClearColor;
};

#endif // WOE_BASE_GRAPHICS_SYSTEM_H