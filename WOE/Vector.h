#ifndef WOE_VECTOR_H
#define WOE_VECTOR_H

#if defined(_WOE_OPENGL)

#include "GLVector.h"

typedef GLVec2	Vec2;
typedef GLVec3	Vec3;
typedef GLVec4	Vec4;

#elif defined(_WOE_DIRECTX)

#include "DXVector.h"

typedef DXVec2	Vec2;
typedef DXVec3	Vec3;
typedef DXVec4	Vec4;

#endif // _WOE_DIRECTX

#endif // WOE_VECTOR_H