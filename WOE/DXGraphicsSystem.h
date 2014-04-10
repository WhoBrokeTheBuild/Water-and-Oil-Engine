#ifndef WOE_DX_GRAPHICS_SYSTEM_H
#define WOE_DX_GRAPHICS_SYSTEM_H

#if defined(_WOE_DIRECTX)

#include "BaseGraphicsSystem.h"

#include "DXHeader.h"

class GameTime;

LRESULT CALLBACK DXWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class DXGraphicsSystem :
	public BaseGraphicsSystem
{
public:

	DXGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen = false );

	virtual ~DXGraphicsSystem( void );

	virtual inline string getClassName( void ) const { return "DX Graphics System"; }

	virtual void update( const GameTime* pGameTime );

	virtual void beginRender( void );
	virtual void endRender( void );

protected:

	virtual void doResizeWindow(const int& width, const int& height);

	virtual void doChangeFullscreen(const bool& fullscreen);

	virtual void doChangeWindowTitle(const string& title);

	HWND							m_Wnd;

	ID3D11Device*					mp_Dev;

	ID3D11DeviceContext*			mp_DevCtx;

	IDXGISwapChain*					mp_SwapChain;

	ID3D11RenderTargetView*			mp_BackBuffer;

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_GRAPHICS_SYSTEM_H