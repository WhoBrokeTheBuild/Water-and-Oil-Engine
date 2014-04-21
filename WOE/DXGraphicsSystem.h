#ifndef WOE_DX_GRAPHICS_SYSTEM_H
#define WOE_DX_GRAPHICS_SYSTEM_H

#if defined(_WOE_DIRECTX)

#include "BaseGraphicsSystem.h"

#include "DXHeader.h"

class GameTime;

LRESULT CALLBACK DXWindowProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

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

	void handleWindowsMessage( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

	inline ID3D11Device*  getDXDevice( void ) const { return mp_Dev; }
	inline ID3D11Device1* getDXDevice1( void ) const { return mp_Dev1; }

	inline ID3D11DeviceContext*  getDXDeviceContext( void ) const { return mp_DevCtx; }
	inline ID3D11DeviceContext1* getDXDeviceContext1( void ) const { return mp_DevCtx1; }

	inline D3D_DRIVER_TYPE getDXDriverType( void ) const { return m_DriverType; }
	inline D3D_FEATURE_LEVEL getDXFeatureLevel( void ) const { return m_FeatureLevel; }

	inline IDXGISwapChain* getDXSwapChain( void ) const { return mp_SwapChain; }

	inline ID3D11RenderTargetView* getDXBackBuffer( void ) const { return mp_BackBuffer; }

protected:

	void cleanup( void );

	bool initWindow( void );
	bool initDevice( void );

	virtual void doResizeWindow(const int& width, const int& height);

	virtual void doChangeFullscreen(const bool& fullscreen);

	virtual void doChangeWindowTitle(const string& title);

	HWND							m_Wnd;

	ID3D11Device*					mp_Dev;

	ID3D11Device1*					mp_Dev1;

	ID3D11DeviceContext*			mp_DevCtx;

	ID3D11DeviceContext1*			mp_DevCtx1;

	IDXGISwapChain*					mp_SwapChain;

	ID3D11RenderTargetView*			mp_BackBuffer;

	D3D_DRIVER_TYPE					m_DriverType;

	D3D_FEATURE_LEVEL				m_FeatureLevel;

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_GRAPHICS_SYSTEM_H