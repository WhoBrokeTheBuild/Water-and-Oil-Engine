#include "GLVector.h"

#if defined(_WOE_OPENGL)

GLVec2 GLVec2::ZERO		= GLVec2(0.0f);
GLVec2 GLVec2::ONE		= GLVec2(1.0f);
GLVec2 GLVec2::NEG_ONE	= GLVec2(-1.0f);

GLVec3 GLVec3::ZERO		= GLVec3(0.0f);
GLVec3 GLVec3::ONE		= GLVec3(1.0f);
GLVec3 GLVec3::NEG_ONE	= GLVec3(-1.0f);

GLVec4 GLVec4::ZERO		= GLVec4(0.0f);
GLVec4 GLVec4::ONE		= GLVec4(1.0f);
GLVec4 GLVec4::NEG_ONE	= GLVec4(-1.0f);

#endif // _WOE_OPENGL