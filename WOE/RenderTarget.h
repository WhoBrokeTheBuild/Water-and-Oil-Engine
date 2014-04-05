#ifndef WOE_RENDER_TARGET_H
#define WOE_RENDER_TARGET_H

#if defined(_WOE_DIRECTX)

#include "DXRenderTarget.h"

typedef DXRenderTarget RenderTarget;

#elif defined(_WOE_OPENGL)

#include "GLRenderTarget.h"

typedef GLRenderTarget RenderTarget;

#endif

#endif // WOE_RENDER_TARGET_H