#ifndef WOE_TEXTURE_H
#define WOE_TEXTURE_H

#if defined(_WOE_DIRECTX)

#include "DXTexture.h"

typedef DXTexture Texture;

#elif defined(_WOE_OPENGL)

#include "GLTexture.h"

typedef GLTexture Texture;

#endif

#endif // WOE_TEXTURE_H