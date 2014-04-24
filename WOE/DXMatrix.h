#ifndef WOE_DX_MATRIX_H
#define WOE_DX_MATRIX_H

#if defined(_WOE_DIRECTX)

#include "DXVector.h"

template <typename T>
struct DXMat
{
public:

	DXMat( void )
		: m_Mat()
	{ }

	DXMat( const DXMat& other )
		: m_Mat(other.m_Mat)
	{ }

	DXMat( const T& other )
		: m_Mat(other)
	{ }

	DXMat( const DirectX::XMMATRIX& mat )
		: m_Mat()
	{
		storeXM(DirectX::XMMatrixIdentity());
	}

	inline void operator=( const DXMat& rhs )
	{
		m_Mat = rhs.m_Mat;
	}

	inline const DXMat operator*( const DXMat& rhs ) const
	{
		return DXMat(m_Mat * rhs.m_Mat);
	}

	DXMat& operator*=( const DXMat& rhs )
	{
		m_Mat *= rhs.m_Mat;
		return *this;
	}

	inline bool operator==( const DXMat& rhs )
	{
		return (m_Mat == rhs.m_Mat);
	}

	inline bool operator!=( const DXMat& rhs )
	{
		return (m_Mat == rhs.m_Mat);
	}

	inline void translate( const DXVec3& amount )
	{
		storeXM(DirectX::XMMatrixMultiply(loadXM(), DirectX::XMMatrixTranslationFromVector(amount.loadXM())));
	}

	inline void rotate( const float& radians, const DXVec3& axis )
	{
		storeXM(DirectX::XMMatrixMultiply(loadXM(), DirectX::XMMatrixRotationAxis(axis.loadXM(), radians)));
	}

	inline void scale( const DXVec3& amount )
	{
		storeXM(DirectX::XMMatrixMultiply(loadXM(), DirectX::XMMatrixScalingFromVector(amount.loadXM())));
	}

	virtual DirectX::XMMATRIX loadXM( void ) const = 0;
	virtual void storeXM( const DirectX::XMMATRIX& mat ) = 0;

protected:

	T	m_Mat;

};

struct DXMat3x3
	: public DXMat<DirectX::XMFLOAT3X3>
{
public:

	DXMat3x3( void )
		: DXMat()
	{ }

	DXMat3x3( const DirectX::XMMATRIX& mat )
		: DXMat(mat)
	{ }

	virtual DirectX::XMMATRIX loadXM( void ) const
	{
		return DirectX::XMLoadFloat3x3(&m_Mat);
	}

	virtual void storeXM( const DirectX::XMMATRIX& mat )
	{
		DirectX::XMStoreFloat3x3(&m_Mat, mat);
	}

};

struct DXMat4x3
	: public DXMat<DirectX::XMFLOAT4X3>
{
public:

	DXMat4x3( void )
		: DXMat()
	{ }

	DXMat4x3( const DirectX::XMMATRIX& mat )
		: DXMat(mat)
	{ }

	virtual DirectX::XMMATRIX loadXM( void ) const
	{
		return DirectX::XMLoadFloat4x3(&m_Mat);
	}

	virtual void storeXM( const DirectX::XMMATRIX& mat )
	{
		DirectX::XMStoreFloat4x3(&m_Mat, mat);
	}

};

struct DXMat4x4
	: public DXMat<DirectX::XMFLOAT4X4>
{
public:

	DXMat4x4( void )
		: DXMat()
	{ }

	DXMat4x4( const DirectX::XMMATRIX& mat )
		: DXMat()
	{ }

	virtual DirectX::XMMATRIX loadXM( void ) const
	{
		return DirectX::XMLoadFloat4x4(&m_Mat);
	}

	virtual void storeXM( const DirectX::XMMATRIX& mat )
	{
		DirectX::XMStoreFloat4x4(&m_Mat, mat);
	}

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_MATRIX_H