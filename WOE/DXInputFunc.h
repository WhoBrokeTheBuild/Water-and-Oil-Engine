#ifndef WOE_DX_INPUT_FUNC_H
#define WOE_DX_INPUT_FUNC_H

#if defined(_WOE_DIRECTX)

#include "DXHeader.h"
#include "Key.h"
#include "MouseButton.h"

Key convertDXKey( WPARAM wParam );

#endif // _WOE_DIRECTX

#endif // WOE_DX_INPUT_FUNC_H