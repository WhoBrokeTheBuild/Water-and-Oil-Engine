#ifndef WOE_GL_MATRIX_H
#define WOE_GL_MATRIX_H

#if defined(_WOE_OPENGL)

#include "GLHeader.h"

template <typename T>
struct GLMat
{
public:

	GLMat( void )
		: m_Mat()
	{ }

	GLMat( const GLMat& other )
		: m_Mat(other.m_Mat)
	{ }

	GLMat( const T& other )
		: m_Mat(other)
	{ }

	inline void operator=( const GLMat& rhs )
	{
		m_Mat = rhs.m_Mat;
	}

	inline const GLMat operator*( const GLMat& rhs ) const
	{
		return GLMat(m_Mat * rhs.m_Mat);
	}

	GLMat& operator*=( const GLMat& rhs )
	{
		m_Mat *= rhs.m_Mat;
		return *this;
	}

	inline bool operator==( const GLMat& rhs )
	{
		return (m_Mat == rhs.m_Mat);
	}

	inline bool operator!=( const GLMat& rhs )
	{
		return (m_Mat == rhs.m_Mat);
	}

	inline void translate( const Vec3& amount )
	{
		m_Mat *= glm::translate(amount.getGLMVec());
	}

	inline void rotate( const float& radians, const Vec3& axis )
	{
		m_Mat *= glm::rotate(axis.getGLMVec(), radians);
	}

	inline void scale( const Vec3& amount )
	{
		m_Mat *= glm::scale(amount.getGLMVec());
	}

	inline T getGLMMat( void ) const 
	{
		return m_Mat;
	}

protected:

	T	m_Mat;

};

struct GLMat3x3
	: public GLMat<glm::mat3x3>
{
public:

	GLMat3x3( void )
		: GLMat()
	{ }

	GLMat3x3( const glm::mat3x3& mat )
		: GLMat(mat)
	{ }

};

struct GLMat4x3
	: public GLMat<glm::mat4x3>
{
public:

	GLMat4x3( void )
		: GLMat()
	{ }

	GLMat4x3( const glm::mat4x3& mat )
		: GLMat(mat)
	{ }

};

struct GLMat4x4
	: public GLMat<glm::mat4x4>
{
public:

	GLMat4x4( void )
		: GLMat()
	{ }

	GLMat4x4( const glm::mat4x4& mat )
		: GLMat(mat)
	{ }

};

#endif // _WOE_OPENGL

#endif // WOE_GL_MATRIX_H