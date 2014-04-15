#ifndef WOE_CAMERA_H
#define WOE_CAMERA_H

#if defined(_WOE_DIRECTX)

#include "DXCamera.h"

typedef DXCamera Camera;

#elif defined(_WOE_OPENGL)

#include "GLCamera.h"

typedef GLCamera Camera;

#endif

#endif // WOE_CAMERA_H