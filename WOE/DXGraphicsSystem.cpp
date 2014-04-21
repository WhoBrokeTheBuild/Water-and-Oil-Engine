#include "DXGraphicsSystem.h"

#if defined(_WOE_DIRECTX)

#include "GameTime.h"
#include "Game.h"
#include "Log.h"

#include <sstream>

using std::stringstream;

DXGraphicsSystem::DXGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen /* = false */ )
	: BaseGraphicsSystem(width, height, title, fullscreen)
{
	Log::Info(getClassName(), "Starting Up");

	if ( ! initWindow())
	{
		cleanup();
	}

	if ( ! initDevice())
	{
		cleanup();
	}

	mp_RenderTarget = New RenderTarget();
	mp_ShaderManager = New ShaderManager();

	Log::Info(getClassName(), "Finished");
}

DXGraphicsSystem::~DXGraphicsSystem(void)
{
	Log::Info(getClassName(), "Shutting Down");

	cleanup();

	Log::Info(getClassName(), "Finished");
}

void DXGraphicsSystem::cleanup()
{
	delete mp_ShaderManager;
	delete mp_RenderTarget;

	mp_SwapChain->SetFullscreenState(FALSE, NULL);

	mp_SwapChain->Release();
	mp_BackBuffer->Release();
	mp_Dev1->Release();
	mp_Dev->Release();
	mp_DevCtx->Release();
	mp_DevCtx1->Release();
}

void DXGraphicsSystem::beginRender( void )
{
	float clearColor[4] = { m_ClearColor.getFloatR(), m_ClearColor.getFloatG(), m_ClearColor.getFloatB(), m_ClearColor.getFloatA() };
	mp_DevCtx->ClearRenderTargetView(mp_BackBuffer, clearColor);
}

void DXGraphicsSystem::endRender( void )
{
	mp_SwapChain->Present(0, 0);
}

void DXGraphicsSystem::update( const GameTime* pGameTime )
{
	static MSG msg;

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void DXGraphicsSystem::doResizeWindow(const int& width, const int& height)
{
}

void DXGraphicsSystem::doChangeFullscreen(const bool& fullscreen)
{
}

void DXGraphicsSystem::doChangeWindowTitle(const string& title)
{
}

void DXGraphicsSystem::handleWindowsMessage( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch(message)
	{
	case WM_PAINT:

		hdc = BeginPaint( hWnd, &ps );
		EndPaint( hWnd, &ps );

		break;
	case WM_DESTROY:

		Game::Instance()->dispatchEvent(Event(Game::EVENT_EXIT));

		break;
	}

}

bool DXGraphicsSystem::initWindow(void)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = DXWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = Game::GetArgs()->getInstance();
	//wc.hIcon = LoadIcon( hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
	//wc.hIconSm = LoadIcon( wcex.hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = "WindowClass";

	if ( ! isFullscreen())
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	if ( ! RegisterClassEx(&wc))
	{
		Log::Error(getClassName(), "RegisterClassEx failed");
		return false;
	}

	RECT wr = {0, 0, getWidth(), getHeight()};
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	stringstream ss;
	ss << getTitle().c_str() << " - DirectX";

	m_Wnd = CreateWindowEx(NULL,
						   "WindowClass",
						   ss.str().c_str(),		// Window Title
						   WS_OVERLAPPEDWINDOW,		// Window Style
						   0, 0,					// Position
						   wr.right - wr.left,		// Width
						   wr.bottom - wr.top,		// Height
						   NULL,
						   NULL, 
						   Game::GetArgs()->getInstance(),
						   NULL);

	if ( ! m_Wnd)
	{
		Log::Error(getClassName(), "CreateWindowEx failed");
		return false;
	}

	ShowWindow(m_Wnd, Game::GetArgs()->getNumCmdShow());

	return true;
}

bool DXGraphicsSystem::initDevice(void)
{
	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	scd.BufferCount = 1;                                    // one back buffer
	scd.BufferDesc.Width = getWidth();
	scd.BufferDesc.Height = getHeight();
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
	scd.BufferDesc.RefreshRate.Numerator = 60;				// FPS
	scd.BufferDesc.RefreshRate.Denominator = 1;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
	scd.OutputWindow = m_Wnd;                               // the window to be used
	scd.SampleDesc.Count = 1;                               // how many multisamples
	scd.SampleDesc.Quality = 0;								
	scd.Windowed = ! isFullscreen();                        // windowed/full-screen mode
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE( driverTypes );

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE( featureLevels );

	UINT createDeviceFlags = 0;

#if defined(_WOE_DEBUG)

	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;

#endif // _WOE_DEBUG

	HRESULT hr;

	for ( unsigned int drvTypeInd = 0; drvTypeInd < numDriverTypes; drvTypeInd++ )
	{
		m_DriverType = driverTypes[drvTypeInd];
		hr = D3D11CreateDeviceAndSwapChain(nullptr, 
										   m_DriverType,
										   nullptr,
										   createDeviceFlags,
										   featureLevels, 
										   numFeatureLevels,
										   D3D11_SDK_VERSION,
										   &scd,
										   &mp_SwapChain, 
										   &mp_Dev, 
										   &m_FeatureLevel,
										   &mp_DevCtx);

		if (hr == E_INVALIDARG)
		{
			// DirectX 11.0 platforms will not recognize D3D_FEATURE_LEVEL_11_1 so we need to retry without it
			hr = D3D11CreateDeviceAndSwapChain(nullptr, 
											   m_DriverType,
											   nullptr,
											   createDeviceFlags,
											   &featureLevels[1], // Skip D3D_FEATURE_LEVEL_11_1
											   numFeatureLevels,
											   D3D11_SDK_VERSION,
											   &scd,
											   &mp_SwapChain, 
											   &mp_Dev, 
											   &m_FeatureLevel,
											   &mp_DevCtx);
		}

		if (SUCCEEDED( hr ))
			break;
	}

	if (FAILED(hr))
	{
		Log::Error(getClassName(), "Failed to create Device and Swap Chain");
		return false;
	}

	hr = mp_Dev->QueryInterface( __uuidof(ID3D11Device1), reinterpret_cast<void**>(&mp_Dev1) );
	if (SUCCEEDED(hr))
	{
		(void)mp_DevCtx->QueryInterface( __uuidof( ID3D11DeviceContext1 ), reinterpret_cast<void**>( &mp_DevCtx1 ) );
	}


	ID3D11Texture2D* tmpBackBuffer;
	hr = mp_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&tmpBackBuffer);
	if (FAILED(hr))
	{
		Log::Error(getClassName(), "Failed to get back buffer");
		return false;
	}

	hr = mp_Dev->CreateRenderTargetView(tmpBackBuffer, NULL, &mp_BackBuffer);
	tmpBackBuffer->Release();
	if (FAILED(hr))
	{
		Log::Error(getClassName(), "Failed to create render target view");
		return false;
	}

	mp_DevCtx->OMSetRenderTargets(1, &mp_BackBuffer, NULL);

	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width  = (float)getWidth();
	viewport.Height = (float)getHeight();
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	mp_DevCtx->RSSetViewports(1, &viewport);

	return true;
}

LRESULT CALLBACK DXWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Game::Instance()->getGraphicsSystem()->handleWindowsMessage(hWnd, message, wParam, lParam);
	Game::Instance()->getInputSystem()->handleWindowsMessage(hWnd, message, wParam, lParam);

	return DefWindowProc(hWnd, message, wParam, lParam);
}

#endif // _WOE_DIRECTX