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

#elif defined(_WOE_DIRECTX)

		DirectX::XMMATRIX mat = DirectX::XMMatrixLookAtLH(eye.loadXM(), center.loadXM(), up.loadXM());

#endif // _WOE_DIRECTX

		return Mat4(mat);
	}

	static inline float Radians( const float& degrees )
	{
#if defined(_WOE_OPENGL)

		return glm::radians(degrees);

#elif defined(_WOE_DIRECTX)

		return DirectX::XMConvertToRadians(degrees);

#endif // _WOE_DIRECTX
	}

	static inline float Degrees( const float& radians )
	{
#if defined(_WOE_OPENGL)

		return glm::degrees(radians);

#elif defined(_WOE_DIRECTX)

		return DirectX::XMConvertToDegrees(radians);

#endif // _WOE_DIRECTX
	}

	static inline Mat4 PerspectiveFOV(float fov, float aspectWidth, float aspectHeight, float vNear, float vFar)
	{
#if defined(_WOE_OPENGL)

		return glm::perspectiveFov(fov, aspectWidth, aspectHeight, vNear, vFar);

#elif defined(_WOE_DIRECTX)

		return DirectX::XMMatrixPerspectiveFovLH(fov, aspectWidth / aspectHeight, vNear, vFar);

#endif // _WOE_DIRECTX
	}

};

#endif // WOE_MATH_HELPER_H