#ifndef WOE_MATRIX_H
#define WOE_MATRIX_H

#if defined(_WOE_OPENGL)

#include "GLMatrix.h"

typedef GLMat3x3	Mat3x3;
typedef GLMat4x3	Mat4x3;
typedef GLMat4x4	Mat4x4;

#elif defined(_WOE_DIRECTX)

#include "DXMatrix.h"

typedef DXMat3x3	Mat3x3;
typedef DXMat4x3	Mat4x3;
typedef DXMat4x4	Mat4x4;

#endif // _WOE_DIRECTX

typedef Mat3x3	Mat3;
typedef Mat4x4	Mat4;

#endif // WOE_MATRIX_H