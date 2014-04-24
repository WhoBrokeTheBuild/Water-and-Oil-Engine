#ifndef WOE_MESH_H
#define WOE_MESH_H

#if defined(_WOE_DIRECTX)

#include "DXMesh.h"

typedef DXMesh Mesh;

#elif defined(_WOE_OPENGL)

#include "GLMesh.h"

typedef GLMesh Mesh;

#endif

#endif // WOE_MESH_H