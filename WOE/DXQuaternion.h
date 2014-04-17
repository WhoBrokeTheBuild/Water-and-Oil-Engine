#ifndef WOE_DX_QUATERNION_H
#define WOE_DX_QUATERNION_H

#if defined(_WOE_DIRECTX)

#include "DXHeader.h"

#include "Vector.h"

class DXQuat
{
public:

	inline DXQuat( void )
		: m_Quat()
	{ }

	inline DXQuat( const DirectX::XMVECTOR& quat )
		: m_Quat()
	{
		DirectX::XMStoreFloat4(&m_Quat, quat);
	}

	inline DXQuat( const float& x, const float& y, const float& z, const float& w )
		: m_Quat()
	{
		DirectX::XMStoreFloat4(&m_Quat, DirectX::XMVectorSet(x, y, z, w));
	}

	static inline DXQuat FromAngleAxis( const float& angle, const Vec3& axis )
	{
		DXQuat out;
		DirectX::XMStoreFloat4(&out.m_Quat, DirectX::XMQuaternionRotationAxis(axis.loadXM(), angle));
		return out;
	}

	inline void normalize( void )
	{
		DirectX::XMStoreFloat4(&m_Quat, DirectX::XMVector4Normalize(DirectX::XMLoadFloat4(&m_Quat)));
	}

	inline DXQuat cross( const DXQuat& other )
	{
		DXQuat out;
		DirectX::XMStoreFloat4(&out.m_Quat, DirectX::XMVector4Normalize(DirectX::XMLoadFloat4(&other.m_Quat)));
		return out;
	}

	inline Vec3 rotateVector( const Vec3& axis )
	{
		Vec4 q1, q2;
		q1.storeXM(DirectX::XMQuaternionConjugate(q1.loadXM()));
		q2.storeXM(DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&m_Quat), DirectX::XMVectorMultiply(Vec4(axis, 1.0f).loadXM(), q1.loadXM())));

		Vec3 out;
		out.storeXM(q2.loadXM());
		return out;
	}

protected:

	DirectX::XMFLOAT4	m_Quat;

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_QUATERNION_H