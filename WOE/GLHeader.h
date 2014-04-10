#ifndef WOE_GL_HEADER_H
#define WOE_GL_HEADER_H

#if defined(_WOE_OPENGL)

#define NOGDI
#include <Windows.h>

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#define INVALID_GL_TEXTURE_ID

#endif // _WOE_OPENGL

#endif // WOE_GL_HEADER_H