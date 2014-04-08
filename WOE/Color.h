#ifndef WOE_COLOR_H
#define WOE_COLOR_H

#include <Arc/ManagedObject.h>

#include <Arc/MathFunctions.h>

#include "Defines.h"

using Arc::ManagedObject;

struct Color :
	public ManagedObject
{
public:

	inline Color( void )
		: m_R(),
		  m_G(),
		  m_B(),
		  m_A(1.0f)
	{ }

	inline Color( const float& r, const float& g, const float& b, const float& a = 1.0f )
		: m_R(r),
		  m_G(g),
		  m_B(b),
		  m_A(a)
	{ }

	inline Color( const int& r, const int& g, const int& b, const int& a = 255 )
		: m_R((float)r / 255.0f),
		  m_G((float)g / 255.0f),
		  m_B((float)b / 255.0f),
		  m_A((float)a / 255.0f)
	{ }

	explicit inline Color( const string& hex )
		: m_R(),
		  m_G(),
		  m_B(),
		  m_A(1.0f)
	{
		setHex(hex);
	}

	inline Color( const Color& rhs )
		: m_R(rhs.m_R),
		  m_G(rhs.m_G),
		  m_B(rhs.m_B),
		  m_A(rhs.m_A)
	{ }

	inline void operator=( const Color& rhs )
	{
		m_R = rhs.m_R;
		m_G = rhs.m_G;
		m_B = rhs.m_B;
		m_A = rhs.m_A;
	}

	virtual inline ~Color( void ) { }

	virtual inline string getClassName( void ) const { return "Color"; }

	void setHex( const string& hex );

	inline void setRGB( const int& r, const int& g, const int& b )  { setRGBA(r, g, b, 255); }
	void setRGBA( const int& r, const int& g, const int& b, const int& a );

	inline void setRGB ( const float& r, const float& g, const float& b ) { setRGBA(r, g, b, 1.0f); }
	void setRGBA( const float& r, const float& g, const float& b, const float& a );

	inline float getFloatR( void ) const { return m_R; }
	inline void setFloatR( float r ) { m_R = Arc::Arc_Clamp(r, 0.0f, 1.0f); }

	inline float getFloatG( void ) const { return m_G; }
	inline void setFloatG( float g ) { m_G = Arc::Arc_Clamp(g, 0.0f, 1.0f); }

	inline float getFloatB( void ) const { return m_B; }
	inline void setFloatB( float b ) { m_B = Arc::Arc_Clamp(b, 0.0f, 1.0f); }

	inline float getFloatA( void ) const { return m_A; }
	inline void setFloatA( float a ) { m_A = Arc::Arc_Clamp(a, 0.0f, 1.0f); }

	inline int getIntR( void ) const { return (int)(m_R * 255.0f); }
	inline void setIntR( float r ) { m_R = Arc::Arc_Clamp((float)r / 255.0f, 0.0f, 1.0f); }

	inline int getIntG( void ) const { return (int)(m_G * 255.0f); }
	inline void setIntG( float g ) { m_G = Arc::Arc_Clamp((float)g / 255.0f, 0.0f, 1.0f); }

	inline int getIntB( void ) const { return (int)(m_B * 255.0f); }
	inline void setIntB( float b ) { m_B = Arc::Arc_Clamp((float)b / 255.0f, 0.0f, 1.0f); }

	inline int getIntA( void ) const { return (int)(m_A * 255.0f); }
	inline void setIntA( float a ) { m_A = Arc::Arc_Clamp((float)a / 255.0f, 0.0f, 1.0f); }

protected:

	float	m_R,
			m_G,
			m_B,
			m_A;

};

#endif // WOE_COLOR_H