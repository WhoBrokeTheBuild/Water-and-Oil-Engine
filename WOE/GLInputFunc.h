#ifndef WOE_GL_INPUT_FUNC_H
#define WOE_GL_INPUT_FUNC_H

#if defined(_WOE_OPENGL)

#include "GLHeader.h"
#include "Key.h"
#include "MouseButton.h"

Key convertKeyGLFW( int key );

MouseButton convertMouseButtonGLFW( int button );

#endif // _WOE_OPENGL

#endif // WOE_GL_INPUT_FUNC_H