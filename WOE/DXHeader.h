#ifndef WOE_DX_HEADER_H
#define WOE_DX_HEADER_H

#if defined(_WOE_DIRECTX)

#define NOGDI
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <d3d11.h>
#include <windowsx.h>
#include <DirectXMath.h>

#endif // _WOE_DIRECTX

#endif // WOE_DX_HEADER_H