#ifndef WOE_GL_QUATERNION_H
#define WOE_GL_QUATERNION_H

#if defined(_WOE_OPENGL)

#include "GLHeader.h"

#include "Vector.h"

class GLQuat
{
public:

	inline GLQuat( void )
		: m_Quat()
	{ }

	inline GLQuat( const glm::quat& quat )
		: m_Quat(quat)
	{ }

	inline GLQuat( const float& x, const float& y, const float& z, const float& w )
		: m_Quat(x, y, z, w)
	{ }

	static inline GLQuat FromAngleAxis( const float& angle, const Vec3& axis )
	{
		return GLQuat(glm::angleAxis(angle, axis.getGLMVec()));
	}

	inline void normalize( void )
	{
		m_Quat = glm::normalize(m_Quat);
	}

	inline GLQuat cross( const GLQuat& other )
	{
		return GLQuat(glm::cross(m_Quat, other.m_Quat));
	}

	inline Vec3 rotateVector( const Vec3& axis )
	{
		return Vec3(glm::rotate(m_Quat, axis.getGLMVec()));
	}

	inline glm::quat getGLMQuat( void ) const 
	{
		return m_Quat;
	}

protected:

	glm::quat	m_Quat;

};

#endif // _WOE_DIRECTX

#endif // WOE_GL_QUATERNION_H