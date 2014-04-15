#ifndef WOE_GL_VECTOR_H
#define WOE_GL_VECTOR_H

#if defined(_WOE_OPENGL)

#include "GLHeader.h"

template <typename T>
struct GLVec
{
public:

	GLVec( void )
		: m_Vec()
	{ }

	GLVec( const GLVec& other )
		: m_Vec(other.m_Vec)
	{ }

	GLVec( const T& other )
		: m_Vec(other)
	{ }

	inline float length( void ) const
	{
		return glm::length(m_Vec);
	}

	inline float lengthSquared( void ) const
	{
		return glm::length2(m_Vec);
	}

	inline void normalize( void )
	{
		m_Vec = glm::normalize(m_Vec);
	}

	inline void operator=( const GLVec& rhs )
	{
		m_Vec = rhs.m_Vec;
	}

	inline const GLVec operator+( const GLVec& rhs ) const
	{
		return GLVec2(m_Vec + rhs.m_Vec);
	}

	inline const GLVec operator-( const GLVec& rhs ) const
	{
		return GLVec(m_Vec - rhs.m_Vec);
	}

	inline const GLVec operator*( const GLVec& rhs ) const
	{
		return GLVec2(m_Vec * rhs.m_Vec);
	}

	inline const GLVec operator/( const GLVec& rhs ) const
	{
		return GLVec(m_Vec / rhs.m_Vec);
	}

	inline const GLVec operator*( float value ) const
	{
		return GLVec(m_Vec * value);
	}

	inline const GLVec operator/( float value ) const
	{
		return GLVec(m_Vec / value);
	}

	GLVec& operator+=( const GLVec& rhs )
	{
		m_Vec += rhs.m_Vec;
	}

	GLVec& operator-=( const GLVec& rhs )
	{
		m_Vec -= rhs.m_Vec;
	}

	GLVec& operator*=( const GLVec& rhs )
	{
		m_Vec *= rhs.m_Vec;
	}

	GLVec& operator/=( const GLVec& rhs )
	{
		m_Vec /= rhs.m_Vec;
	}

	GLVec& operator*=( float value )
	{
		m_Vec *= value;
	}

	GLVec& operator/=( float value )
	{
		m_Vec *= value;
	}

	inline bool operator==( const GLVec& rhs )
	{
		return (m_Vec == rhs.m_Vec);
	}

	inline bool operator!=( const GLVec& rhs )
	{
		return (m_Vec == rhs.m_Vec);
	}

	bool operator<( const GLVec& rhs ) const
	{
		return (m_Vec == rhs.m_Vec);
	}

	bool operator>( const GLVec& rhs ) const
	{
		return (m_Vec == rhs.m_Vec);
	}

	bool operator<=( const GLVec& rhs ) const
	{
		return (m_Vec == rhs.m_Vec);
	}

	bool operator>=( const GLVec& rhs ) const
	{
		return (m_Vec == rhs.m_Vec);
	}

	inline T getGLMVec( void ) const
	{
		return m_Vec;
	}

protected:

	T	m_Vec;

};

struct GLVec2
	: public GLVec<glm::vec2>
{
public:

	GLVec2( void )
		: GLVec()
	{ }

	GLVec2( const glm::vec2& vec )
		: GLVec(vec)
	{ }

	GLVec2( const float& all )
		: GLVec(glm::vec2(all))
	{ }

	GLVec2( const float& x, const float& y )
		: GLVec(glm::vec2(x, y))
	{ }

};

struct GLVec3
	: public GLVec<glm::vec3>
{
public:

	GLVec3( void )
		: GLVec()
	{ }

	GLVec3( const glm::vec3& vec )
		: GLVec(vec)
	{ }

	GLVec3( const float& all )
		: GLVec(glm::vec3(all))
	{ }

	GLVec3( const float& x, const float& y, const float& z )
		: GLVec(glm::vec3(x, y, z))
	{ }

	inline float dot( const GLVec3& rhs ) const
	{
		return glm::dot(m_Vec, rhs.m_Vec);
	}

	inline GLVec3 cross( const GLVec3& rhs ) const
	{
		GLVec3 out;
		out.m_Vec = glm::cross(m_Vec, rhs.m_Vec);
		return out;
	}

};

struct GLVec4
	: public GLVec<glm::vec4>
{
public:

	GLVec4( void )
		: GLVec()
	{ }

	GLVec4( const glm::vec4& vec )
		: GLVec(vec)
	{ }

	GLVec4( const float& all )
		: GLVec(glm::vec4(all))
	{ }

	GLVec4( const float& x, const float& y, const float& z, const float& w )
		: GLVec(glm::vec4(x, y, z, w))
	{ }

	inline float dot( const GLVec4& rhs ) const
	{
		return glm::dot(m_Vec, rhs.m_Vec);
	}

};

#endif // _WOE_OPENGL

#endif // WOE_GL_VECTOR_H