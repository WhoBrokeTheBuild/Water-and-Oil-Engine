#ifndef WOE_INPUT_SYSTEM_H
#define WOE_INPUT_SYSTEM_H

#if defined(_WOE_DIRECTX)

#include "DXInputSystem.h"

typedef DXInputSystem InputSystem;

#elif defined(_WOE_OPENGL)

#include "GLInputSystem.h"

typedef GLInputSystem InputSystem;

#endif

#endif // WOE_INPUT_SYSTEM_H