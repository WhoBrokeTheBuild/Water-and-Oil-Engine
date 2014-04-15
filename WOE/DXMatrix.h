#ifndef WOE_DX_MATRIX_H
#define WOE_DX_MATRIX_H

#if defined(_WOE_DIRECTX)

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

protected:

	T	m_Mat;

};

struct DXMat3x3
	: public DXMat<DirectX::XMFLOAT3X3>
{
public:

	DXMat3x3( void )
		: DXMat()
	{
		DirectX::XMStoreFloat3x3(&m_Mat, DirectX::XMMatrixIdentity());
	}

	DXMat3x3( const DirectX::XMMATRIX& mat )
		: DXMat()
	{
		XMStoreFloat3x3(&m_Mat, mat);
	}

};

struct DXMat4x3
	: public DXMat<DirectX::XMFLOAT4X3>
{
public:

	DXMat4x3( void )
		: DXMat()
	{
		DirectX::XMStoreFloat4x3(&m_Mat, DirectX::XMMatrixIdentity());
	}

	DXMat4x3( const DirectX::XMMATRIX& mat )
		: DXMat()
	{
		XMStoreFloat4x3(&m_Mat, mat);
	}

};

struct DXMat4x4
	: public DXMat<DirectX::XMFLOAT4X4>
{
public:

	DXMat4x4( void )
		: DXMat()
	{
		DirectX::XMStoreFloat4x4(&m_Mat, DirectX::XMMatrixIdentity());
	}

	DXMat4x4( const DirectX::XMMATRIX& mat )
		: DXMat()
	{
		XMStoreFloat4x4(&m_Mat, mat);
	}

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_MATRIX_H