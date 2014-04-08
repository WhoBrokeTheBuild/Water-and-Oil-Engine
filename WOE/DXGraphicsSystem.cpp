#include "DXGraphicsSystem.h"

#if defined(_WOE_DIRECTX)

#include "GameTime.h"
#include "Game.h"

#include <sstream>

using std::stringstream;

DXGraphicsSystem::DXGraphicsSystem( const int& width, const int& height, const string& title, const bool& fullscreen /* = false */ )
	: BaseGraphicsSystem(width, height, title, fullscreen)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = DXWindowProc;
	wc.hInstance = Game::GetArgs()->getInstance();
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass";

	RegisterClassEx(&wc);

	RECT wr = {0, 0, width, height};
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	wr.right -= wr.left;
	wr.bottom -= wr.top;

	stringstream ss;
	ss << title.c_str() << " - DirectX";

	m_Wnd = CreateWindowEx(NULL,
						   "WindowClass",
						   ss.str().c_str(),			// Window Title
						   WS_OVERLAPPEDWINDOW,		// Window Style
						   0, 0,					// Position
						   wr.right, wr.bottom,			// Size
						   NULL,
						   NULL, 
						   Game::GetArgs()->getInstance(),
						   NULL);

	ShowWindow(m_Wnd, Game::GetArgs()->getNumCmdShow());

	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	scd.BufferCount = 1;                                    // one back buffer
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
	scd.OutputWindow = m_Wnd;                                // the window to be used
	scd.SampleDesc.Count = 4;                               // how many multisamples
	scd.Windowed = TRUE;                                    // windowed/full-screen mode

	// create a device, device context and swap chain using the information in the scd struct
	D3D11CreateDeviceAndSwapChain(NULL,
								  D3D_DRIVER_TYPE_HARDWARE,
								  NULL,
								  NULL,
								  NULL,
								  NULL,
								  D3D11_SDK_VERSION,
								  &scd,
								  &mp_SwapChain,
								  &mp_Dev,
								  NULL,
								  &mp_DevCtx);

	ID3D11Texture2D* tmpBackBuffer;
	mp_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&tmpBackBuffer);

	mp_Dev->CreateRenderTargetView(tmpBackBuffer, NULL, &mp_BackBuffer);
	tmpBackBuffer->Release();

	mp_DevCtx->OMSetRenderTargets(1, &mp_BackBuffer, NULL);

	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width  = (float)width;
	viewport.Height = (float)height;

	mp_DevCtx->RSSetViewports(1, &viewport);
}

DXGraphicsSystem::~DXGraphicsSystem(void)
{
	mp_SwapChain->Release();
	mp_Dev->Release();
	mp_DevCtx->Release();
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

void DXGraphicsSystem::update(const GameTime* pGameTime)
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

LRESULT CALLBACK DXWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		
			Game::Instance()->getGraphicsSystem()->dispatchEvent(Event(Game::EVENT_EXIT));
			return 0;

		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

#endif // _WOE_DIRECTX