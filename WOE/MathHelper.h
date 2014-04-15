#ifndef WOE_MATH_HELPER_H
#define WOE_MATH_HELPER_H

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include "Vector.h"
#include "Matrix.h"

class MathHelper
{
public:

	static float	INFINITY,
					PI,
					PI2,
					PI_OVER_2,
					PI_OVER_4;


	static inline Mat4 LookAt( const Vec3& eye, const Vec3& center, const Vec3& up )
	{
#if defined(_WOE_OPENGL)

		glm::mat4 mat = glm::lookAt(eye.getGLMVec(), center.getGLMVec(), up.getGLMVec());

		return Mat4(mat);

#elif defined(_WOE_DIRECTX)

		DirectX::XMMATRIX mat = DirectX::XMMatrixLookAtLH(eye.loadXM(), center.loadXM(), up.loadXM());

		return Mat4(mat);

#endif // _WOE_DIRECTX
	}
	
};

#endif // WOE_MATH_HELPER_H