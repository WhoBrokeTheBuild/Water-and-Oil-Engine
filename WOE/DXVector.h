#ifndef WOE_DX_VECTOR_H
#define WOE_DX_VECTOR_H

#if defined(_WOE_DIRECTX)

#include "DXHeader.h"

template <typename T>
struct DXVec
{
public:

	DXVec( const DXVec& other )
		: m_Vec(other.m_Vec)
	{ }

	DXVec( const T& other )
		: m_Vec(other)
	{ }

	inline void operator=( const DXVec& rhs )
	{
		m_Vec = rhs.m_Vec;
	}

	inline float length( void ) const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector2Length(loadXM()));
	}

	inline float lengthSquared( void ) const
	{
		return DirectX::XMVectorGetX(DirectX::XMVector2LengthSq(loadXM()));
	}

	inline const DXVec operator+( const DXVec& rhs ) const
	{
		DXVec out;
		out += rhs;
		return out;
	}

	inline const DXVec operator-( const DXVec& rhs ) const
	{
		DXVec out;
		out -= rhs;
		return out;
	}

	inline const DXVec operator*( const DXVec& rhs ) const
	{
		DXVec out;
		out *= rhs;
		return out;
	}

	inline const DXVec operator/( const DXVec& rhs ) const
	{
		DXVec out;
		out /= rhs;
		return out;
	}

	DXVec& operator+=( const DXVec& rhs )
	{
		storeXM(DirectX::XMVectorAdd(loadXM(), rhs.loadXM()));
		return *this;
	}

	DXVec& operator-=( const DXVec& rhs )
	{
		storeXM(DirectX::XMVectorSubtract(loadXM(), rhs.loadXM()));
		return *this;
	}

	DXVec& operator*=( const DXVec& rhs )
	{
		storeXM(DirectX::XMVectorMultiply(loadXM(), rhs.loadXM()));
		return *this;
	}

	DXVec& operator/=( const DXVec& rhs )
	{
		storeXM(DirectX::XMVectorDivide(loadXM(), rhs.loadXM()));
		return *this;
	}

	DXVec& operator*=( float value )
	{
		storeXM(DirectX::XMVectorScale(loadXM(), value));
		return *this;
	}

	DXVec& operator/=( float value )
	{
		storeXM(DirectX::XMVectorScale(loadXM(), 1.0f / value));
		return *this;
	}

	inline bool operator!=( const DXVec& rhs )
	{
		return ! (*this == rhs);
	}

	inline T getXMVec( void ) const
	{
		return m_Vec;
	}

protected:

	virtual DirectX::XMVECTOR loadXM( void ) const = 0;
	virtual void storeXM( const DirectX::XMVECTOR& vec ) = 0;

	T	m_Vec;

};

struct DXVec2
	: public DXVec<DirectX::XMFLOAT2>
{
public:

	DXVec2( void )
		: DXVec(DirectX::XMFLOAT2(0.0f, 0.0f))
	{ }

	explicit DXVec2( const float& all )
		: DXVec(DirectX::XMFLOAT2(all, all))
	{ }

	DXVec2( const float& x, const float& y )
		: DXVec(DirectX::XMFLOAT2(x, y))
	{ }

	virtual inline DirectX::XMVECTOR loadXM( void ) const
	{
		return DirectX::XMLoadFloat2(&m_Vec);
	}

	virtual inline void storeXM( const DirectX::XMVECTOR& vec )
	{
		DirectX::XMStoreFloat2(&m_Vec, vec);
	}

	inline void normalize( void )
	{
		storeXM(DirectX::XMVector2Normalize(loadXM()));
	}

	inline const DXVec2 operator*( float value ) const
	{
		return DXVec2(m_Vec.x * value, m_Vec.y * value);
	}

	inline const DXVec2 operator/( float value ) const
	{
		return DXVec2(m_Vec.x / value, m_Vec.y / value);
	}

	inline bool operator==( const DXVec2& rhs )
	{
		return (m_Vec.x == rhs.m_Vec.x && m_Vec.y == rhs.m_Vec.y);
	}

	bool operator<( const DXVec2& rhs ) const
	{
		return (m_Vec.x < rhs.m_Vec.x && m_Vec.y < rhs.m_Vec.y);
	}

	bool operator>( const DXVec2& rhs ) const
	{
		return (m_Vec.x > rhs.m_Vec.x && m_Vec.y > rhs.m_Vec.y);
	}

	bool operator<=( const DXVec2& rhs ) const
	{
		return (m_Vec.x <= rhs.m_Vec.x && m_Vec.y <= rhs.m_Vec.y);
	}

	bool operator>=( const DXVec2& rhs ) const
	{
		return (m_Vec.x >= rhs.m_Vec.x && m_Vec.y >= rhs.m_Vec.y);
	}

};

struct DXVec3
	: public DXVec<DirectX::XMFLOAT3>
{
public:

	DXVec3( void )
		: DXVec(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f))
	{ }

	explicit DXVec3( const float& all )
		: DXVec(DirectX::XMFLOAT3(all, all, all))
	{ }

	DXVec3( const float& x, const float& y, const float& z )
		: DXVec(DirectX::XMFLOAT3(x, y, z))
	{ }

	virtual inline DirectX::XMVECTOR loadXM( void ) const
	{
		return DirectX::XMLoadFloat3(&m_Vec);
	}

	virtual inline void storeXM( const DirectX::XMVECTOR& vec )
	{
		DirectX::XMStoreFloat3(&m_Vec, vec);
	}

	inline float dot( const DXVec3& rhs )
	{
		return DirectX::XMVectorGetX(DirectX::XMVector3Dot(loadXM(), rhs.loadXM()));
	}

	inline void normalize( void )
	{
		storeXM(DirectX::XMVector3Normalize(loadXM()));
	}

	inline DXVec3 cross( const DXVec3& rhs ) const
	{
		DXVec3 out;
		out.storeXM(DirectX::XMVector3Cross(loadXM(), rhs.loadXM()));
		return out;
	}

	inline const DXVec3 operator*( float value ) const
	{
		return DXVec3(m_Vec.x * value, m_Vec.y * value, m_Vec.z * value);
	}

	inline const DXVec3 operator/( float value ) const
	{
		return DXVec3(m_Vec.x / value, m_Vec.y / value, m_Vec.z / value);
	}

	inline bool operator==( const DXVec3& rhs )
	{
		return (m_Vec.x == rhs.m_Vec.x && m_Vec.y == rhs.m_Vec.y && m_Vec.z == rhs.m_Vec.z);
	}

	bool operator<( const DXVec3& rhs ) const
	{
		return (m_Vec.x < rhs.m_Vec.x && m_Vec.y < rhs.m_Vec.y && m_Vec.z < rhs.m_Vec.z);
	}

	bool operator>( const DXVec3& rhs ) const
	{
		return (m_Vec.x > rhs.m_Vec.x && m_Vec.y > rhs.m_Vec.y && m_Vec.z > rhs.m_Vec.z);
	}

	bool operator<=( const DXVec3& rhs ) const
	{
		return (m_Vec.x <= rhs.m_Vec.x && m_Vec.y <= rhs.m_Vec.y && m_Vec.z <= rhs.m_Vec.z);
	}

	bool operator>=( const DXVec3& rhs ) const
	{
		return (m_Vec.x >= rhs.m_Vec.x && m_Vec.y >= rhs.m_Vec.y && m_Vec.z >= rhs.m_Vec.z);
	}
};

struct DXVec4
	: public DXVec<DirectX::XMFLOAT4>
{
public:

	DXVec4( void )
		: DXVec(DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f))
	{ }

	explicit DXVec4( const float& all )
		: DXVec(DirectX::XMFLOAT4(all, all, all, all))
	{ }

	DXVec4( const float& x, const float& y, const float& z, const float& w )
		: DXVec(DirectX::XMFLOAT4(x, y, z, w))
	{ }

	virtual inline DirectX::XMVECTOR loadXM( void ) const
	{
		return DirectX::XMLoadFloat4(&m_Vec);
	}

	virtual inline void storeXM( const DirectX::XMVECTOR& vec )
	{
		DirectX::XMStoreFloat4(&m_Vec, vec);
	}

	inline float dot( const DXVec4& rhs )
	{
		return DirectX::XMVectorGetX(DirectX::XMVector4Dot(loadXM(), rhs.loadXM()));
	}

	inline void normalize( void )
	{
		storeXM(DirectX::XMVector4Normalize(loadXM()));
	}

	inline const DXVec4 operator*( float value ) const
	{
		return DXVec4(m_Vec.x * value, m_Vec.y * value, m_Vec.z * value, m_Vec.w * value);
	}

	inline const DXVec4 operator/( float value ) const
	{
		return DXVec4(m_Vec.x / value, m_Vec.y / value, m_Vec.z / value, m_Vec.w / value);
	}

	inline bool operator==( const DXVec4& rhs )
	{
		return (m_Vec.x == rhs.m_Vec.x && m_Vec.y == rhs.m_Vec.y && m_Vec.z == rhs.m_Vec.z && m_Vec.w == rhs.m_Vec.w);
	}

	bool operator<( const DXVec4& rhs ) const
	{
		return (m_Vec.x < rhs.m_Vec.x && m_Vec.y < rhs.m_Vec.y && m_Vec.z < rhs.m_Vec.z && m_Vec.w < rhs.m_Vec.w);
	}

	bool operator>( const DXVec4& rhs ) const
	{
		return (m_Vec.x > rhs.m_Vec.x && m_Vec.y > rhs.m_Vec.y && m_Vec.z > rhs.m_Vec.z && m_Vec.w > rhs.m_Vec.w);
	}

	bool operator<=( const DXVec4& rhs ) const
	{
		return (m_Vec.x <= rhs.m_Vec.x && m_Vec.y <= rhs.m_Vec.y && m_Vec.z <= rhs.m_Vec.z && m_Vec.w <= rhs.m_Vec.w);
	}

	bool operator>=( const DXVec4& rhs ) const
	{
		return (m_Vec.x >= rhs.m_Vec.x && m_Vec.y >= rhs.m_Vec.y && m_Vec.z >= rhs.m_Vec.z && m_Vec.w >= rhs.m_Vec.w);
	}
};

#endif // _WOE_DIRECTX

#endif // WOE_DX_VECTOR_H