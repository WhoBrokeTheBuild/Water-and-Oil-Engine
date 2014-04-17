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

	inline const GLVec operator+( const GLVec& rhs ) const
	{
		return GLVec(m_Vec + rhs.m_Vec);
	}

	inline const GLVec operator-( const GLVec& rhs ) const
	{
		return GLVec(m_Vec - rhs.m_Vec);
	}

	inline const GLVec operator*( const GLVec& rhs ) const
	{
		return GLVec(m_Vec * rhs.m_Vec);
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
		return *this;
	}

	GLVec& operator-=( const GLVec& rhs )
	{
		m_Vec -= rhs.m_Vec;
		return *this;
	}

	GLVec& operator*=( const GLVec& rhs )
	{
		m_Vec *= rhs.m_Vec;
		return *this;
	}

	GLVec& operator/=( const GLVec& rhs )
	{
		m_Vec /= rhs.m_Vec;
		return *this;
	}

	GLVec& operator*=( float value )
	{
		m_Vec *= value;
		return *this;
	}

	GLVec& operator/=( float value )
	{
		m_Vec *= value;
		return *this;
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

	static GLVec2		ZERO,
						ONE,
						NEG_ONE;

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

	GLVec2( const GLVec<glm::vec2>& vec )
		: GLVec(vec)
	{ }

	inline GLVec2& operator=( const GLVec2& rhs )
	{
		m_Vec = rhs.m_Vec;
		return *this;
	}

	inline float getX( void ) const 
	{
		return m_Vec.x;
	}

	inline float getY( void ) const 
	{
		return m_Vec.y;
	}

	inline void setX( const float& x )
	{
		m_Vec.x = x;
	}

	inline void setY( const float& y )
	{
		m_Vec.y = y;
	}

	inline void addX( const float& x )
	{
		m_Vec.x += x;
	}

	inline void addY( const float& y )
	{
		m_Vec.y += y;
	}

	inline void subX( const float& x )
	{
		m_Vec.x -= x;
	}

	inline void subY( const float& y )
	{
		m_Vec.y -= y;
	}

};

struct GLVec3
	: public GLVec<glm::vec3>
{
public:

	static GLVec3		ZERO,
						ONE,
						NEG_ONE;

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

	GLVec3( const GLVec<glm::vec3>& vec )
		: GLVec(vec)
	{ }

	GLVec3( const GLVec2& other, const float& z )
		: GLVec(glm::vec3(other.getX(), other.getY(), z))
	{ }

	inline GLVec3& operator=( const GLVec3& rhs )
	{
		m_Vec = rhs.m_Vec;
		return *this;
	}

	inline float getX( void ) const 
	{
		return m_Vec.x;
	}

	inline float getY( void ) const 
	{
		return m_Vec.y;
	}

	inline float getZ( void ) const 
	{
		return m_Vec.z;
	}

	inline void setX( const float& x )
	{
		m_Vec.x = x;
	}

	inline void setY( const float& y )
	{
		m_Vec.y = y;
	}

	inline void setZ( const float& z )
	{
		m_Vec.z = z;
	}

	inline void addX( const float& x )
	{
		m_Vec.x += x;
	}

	inline void addY( const float& y )
	{
		m_Vec.y += y;
	}

	inline void addZ( const float& z )
	{
		m_Vec.z += z;
	}

	inline void subX( const float& x )
	{
		m_Vec.x -= x;
	}

	inline void subY( const float& y )
	{
		m_Vec.y -= y;
	}

	inline void subZ( const float& z )
	{
		m_Vec.z -= z;
	}

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

	static GLVec4		ZERO,
						ONE,
						NEG_ONE;

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

	GLVec4( const GLVec<glm::vec4>& vec )
		: GLVec(vec)
	{ }

	GLVec4( const GLVec3& other, const float& w )
		: GLVec(glm::vec4(other.getX(), other.getY(), other.getZ(), w))
	{ }

	inline GLVec4& operator=( const GLVec4& rhs )
	{
		m_Vec = rhs.m_Vec;
		return *this;
	}

	inline float getX( void ) const 
	{
		return m_Vec.x;
	}

	inline float getY( void ) const 
	{
		return m_Vec.y;
	}

	inline float getZ( void ) const 
	{
		return m_Vec.z;
	}

	inline float getW( void ) const 
	{
		return m_Vec.w;
	}

	inline void setX( const float& x )
	{
		m_Vec.x = x;
	}

	inline void setY( const float& y )
	{
		m_Vec.y = y;
	}

	inline void setZ( const float& z )
	{
		m_Vec.z = z;
	}

	inline void setW( const float& w )
	{
		m_Vec.w = w;
	}

	inline void addX( const float& x )
	{
		m_Vec.x += x;
	}

	inline void addY( const float& y )
	{
		m_Vec.y += y;
	}

	inline void addZ( const float& z )
	{
		m_Vec.z += z;
	}

	inline void addW( const float& w )
	{
		m_Vec.w += w;
	}

	inline void subX( const float& x )
	{
		m_Vec.x -= x;
	}

	inline void subY( const float& y )
	{
		m_Vec.y -= y;
	}

	inline void subZ( const float& z )
	{
		m_Vec.z -= z;
	}

	inline void subW( const float& w )
	{
		m_Vec.w -= w;
	}

	inline float dot( const GLVec4& rhs ) const
	{
		return glm::dot(m_Vec, rhs.m_Vec);
	}

};

#endif // _WOE_OPENGL

#endif // WOE_GL_VECTOR_H