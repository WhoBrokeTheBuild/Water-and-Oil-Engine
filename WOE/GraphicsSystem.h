#ifndef WOE_GRAPHICS_SYSTEM_H
#define WOE_GRAPHICS_SYSTEM_H

#if defined(_WOE_DIRECTX)

#include "DXGraphicsSystem.h"

typedef DXGraphicsSystem GraphicsSystem;

#elif defined(_WOE_OPENGL)

#include "GLGraphicsSystem.h"

typedef GLGraphicsSystem GraphicsSystem;

#endif

#endif // WOE_GRAPHICS_SYSTEM_H