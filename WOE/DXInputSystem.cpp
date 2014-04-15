#include "DXInputSystem.h"

#if defined(_WOE_DIRECTX)

#include "Log.h"
#include "DXInputFunc.h"

DXInputSystem::DXInputSystem( void )
	: BaseInputSystem()
{
	Log::Info(getClassName(), "Starting Up");

	Log::Info(getClassName(), "Finished");
}

DXInputSystem::~DXInputSystem( void )
{
	Log::Info(getClassName(), "Shutting Down");

	Log::Info(getClassName(), "Finished");
}

void DXInputSystem::update( const GameTime* pGameTime )
{

}

void DXInputSystem::handleWindowsMessage( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch(message)
	{
	case WM_MOUSEMOVE:
		{
			const int& mouseX = GET_X_LPARAM(lParam);
			const int& mouseY = GET_Y_LPARAM(lParam);

			hookMouseMoved((float)mouseX, (float)mouseY);
		}
		break;
	case WM_LBUTTONDOWN:

		hookMouseButtonDown(MouseButton::WOE_MOUSE_BUTTON_LEFT);

		break;
	case WM_LBUTTONUP:
		
		hookMouseButtonUp(MouseButton::WOE_MOUSE_BUTTON_LEFT);

		break;
	case WM_MBUTTONDOWN:

		hookMouseButtonDown(MouseButton::WOE_MOUSE_BUTTON_MIDDLE);

		break;
	case WM_MBUTTONUP:

		hookMouseButtonUp(MouseButton::WOE_MOUSE_BUTTON_MIDDLE);

		break;
	case WM_RBUTTONDOWN:

		hookMouseButtonDown(MouseButton::WOE_MOUSE_BUTTON_RIGHT);

		break;
	case WM_RBUTTONUP:

		hookMouseButtonUp(MouseButton::WOE_MOUSE_BUTTON_RIGHT);

		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:

		hookKeyDown(convertDXKey(wParam));

		break;
	case WM_KEYUP:
	case WM_SYSKEYUP:

		hookKeyUp(convertDXKey(wParam));

		break;
	}
}

#endif // _WOE_DIRECTX