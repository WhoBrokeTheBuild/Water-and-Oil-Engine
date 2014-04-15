#ifndef WOE_DX_INPUT_SYSTEM_H
#define WOE_DX_INPUT_SYSTEM_H

#include "BaseInputSystem.h"

#if defined(_WOE_DIRECTX)

#include "DXHeader.h"
#include "Key.h"
#include "MouseButton.h"
#include "ScrollWheelDir.h"

class DXInputSystem
	: public BaseInputSystem
{
public:

	DXInputSystem( void );

	~DXInputSystem( void );

	virtual inline string getClassName( void ) const { return "DX Input System"; }

	virtual void update( const GameTime* pGameTime );

	void handleWindowsMessage( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

protected:

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_INPUT_SYSTEM_H