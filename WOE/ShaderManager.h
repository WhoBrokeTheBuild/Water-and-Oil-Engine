#ifndef WOE_SHADER_MANAGER_H
#define WOE_SHADER_MANAGER_H

#if defined(_WOE_DIRECTX)

#include "DXShaderManager.h"

typedef DXShaderManager ShaderManager;

#elif defined(_WOE_OPENGL)

#include "GLShaderManager.h"

typedef GLShaderManager ShaderManager;

#endif

#endif // WOE_SHADER_MANAGER_H