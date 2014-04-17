#include "Camera.h"

Mat4 Camera::getViewMatrix( void )
{
	m_Dir = m_LookAt - m_Pos;
	m_Dir.normalize();

	Vec3 pitchAxis = m_Dir.cross(m_Up);

	Quat pitchQ = Quat::FromAngleAxis(m_Pitch, pitchAxis);
	Quat yawQ   = Quat::FromAngleAxis(m_Yaw, m_Up);
	
	Quat tmp = pitchQ.cross(yawQ);
	tmp.normalize();

	m_Dir = tmp.rotateVector(m_Dir);
	m_Pos += m_PosDelta;

	m_LookAt = m_Pos + m_Dir;

	m_View = MathHelper::LookAt(getPos(), m_LookAt, getUp());

	m_Pitch *= 0.5f;
	m_Yaw   *= 0.5f;
	m_PosDelta *= 0.8f;

	return m_View;
}

void Camera::moveForward( const float& amount )
{
	m_PosDelta += getDir() * amount;
}

void Camera::moveBackward( const float& amount )
{
	m_PosDelta -= getDir() * amount;
}

void Camera::moveLeft( const float& amount )
{
	m_PosDelta -= getRight() * amount;
}

void Camera::moveRight( const float& amount )
{
	m_PosDelta += getRight() * amount;
}

void Camera::setPerspective( const float& fov, const float& width, const float& height, const float& vNear, const float& vFar )
{
	m_FOV = fov;
	m_AspectWidth = width;
	m_AspectHeight = height;
	m_Near = vNear;
	m_Far = vFar;
}

void Camera::setDir( const float& x, const float& y, const float& z )
{
	m_Dir.setX(x); 
	m_Dir.setY(y); 
	m_Dir.setZ(z);

	m_LookAt = m_Pos + m_Dir;
}

Mat4 Camera::getProjectionMatrix( void )
{
	if ( ! m_ProjUpdated)
		return m_Proj;

	if (m_AspectWidth <= 0.0f || m_AspectHeight <= 0.0f || m_FOV <= 0.0f)
		return Mat4();

	m_Proj = MathHelper::PerspectiveFOV(m_FOV, m_AspectWidth, m_AspectHeight, m_Near, m_Far);

	return m_Proj;
}

void Camera::reset( float width, float height )
{
	setPos(m_InitialPos);
	setDir(m_InitialDir);
	setUp(m_InitialUp);

	setPerspective(m_InitialFOV, width, height, m_InitialNear, m_InitialFar);

	m_Pitch = 0.0f;
	m_Yaw = 0.0f;
	m_Speed = m_InitialSpeed;
	m_PosDelta = Vec3::ZERO;
}

void Camera::changePitch( const float& amount )
{
	m_Pitch += amount;

	//Check bounds for the camera pitch
	if (m_Pitch > 360.0f)
		m_Pitch -= 360.0f;
	else if (m_Pitch < -360.0f)
		m_Pitch += 360.0f;
}

void Camera::changeYaw( const float& amount )
{
	//This controls how the heading is changed if the camera is pointed straight up or down
	//The heading delta direction changes
	if (m_Pitch > MathHelper::Radians(90.0f) && m_Pitch < MathHelper::Radians(270.0f) || (m_Pitch < MathHelper::Radians(-90.0f) && m_Pitch > MathHelper::Radians(-270.0f)))
		m_Yaw -= amount;
	else 
		m_Yaw += amount;

	//Check bounds for the camera heading
	if (m_Yaw > 360.0f) 
		m_Yaw -= 360.0f;
	else if (m_Yaw < -360.0f) 
		m_Yaw += 360.0f;
}
