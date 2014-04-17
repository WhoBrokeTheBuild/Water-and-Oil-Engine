#ifndef WOE_QUATERNION_H
#define WOE_QUATERNION_H

#if defined(_WOE_OPENGL)

#include "GLQuaternion.h"

typedef GLQuat	Quat;

#elif defined(_WOE_DIRECTX)

#include "DXQuaternion.h"

typedef DXQuat	Quat;

#endif // _WOE_DIRECTX

#endif // WOE_QUATERNION_H