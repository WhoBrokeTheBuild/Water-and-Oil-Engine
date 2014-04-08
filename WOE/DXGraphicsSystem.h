#ifndef WOE_DX_GRAPHICS_SYSTEM_H
#define WOE_DX_GRAPHICS_SYSTEM_H

#include "BaseGraphicsSystem.h"

#define NOGDI
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3d11.h>
//#include <d3dx11.h>
//#include <d3dx10.h>

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

#endif // WOE_DX_GRAPHICS_SYSTEM_H