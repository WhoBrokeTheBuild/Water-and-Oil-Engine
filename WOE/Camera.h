#ifndef WOE_CAMERA_H
#define WOE_CAMERA_H

#include <Arc/ManagedObject.h>

#include "MathHelper.h"
#include "Vector.h"
#include "Matrix.h"
#include "Quaternion.h"

using Arc::ManagedObject;

class Camera :
	public ManagedObject
{
public:

	inline Camera( const float& width, const float& height, const Vec3& pos, const Vec3& dir, const Vec3& up, const float& fov, const float& vNear, const float& vFar, const float& speed )
		: m_ProjUpdated		(true),
		m_InitialPos		(pos),
		m_InitialUp			(up),
		m_InitialDir		(dir),
		m_InitialFOV		(fov),
		m_InitialNear		(vNear),
		m_InitialFar		(vFar),
		m_InitialSpeed		(speed)//,
		//m_Orient			(1, 0, 0, 0)
	{
		reset(width, height);
		getViewMatrix();
	}

	virtual inline ~Camera( void ) { }

	virtual inline string getClassName( void ) const { return "Camera"; }

	void reset( float width, float height );
	inline void reset( void ) { reset(m_AspectWidth, m_AspectHeight); }

	inline Vec3 getPos( void ) const      { return m_Pos; }
	inline void setPos( const Vec3& pos ) { setPos(pos.getX(), pos.getY(), pos.getZ()); }
	inline void setPos( const float& x, const float& y, const float& z )
	{ 
		m_Pos.setX(x);
		m_Pos.setY(y); 
		m_Pos.setZ(z);
	}

	inline Vec3 getDir( void ) const	  { return m_Dir; }
	inline void setDir( const Vec3& dir ) { setDir(dir.getX(), dir.getY(), dir.getZ()); }
	void setDir( const float& x, const float& y, const float& z );

	inline Vec3 getUp( void ) const     { return m_Up; }
	inline void setUp( const Vec3& up ) { setUp(up.getX(), up.getY(), up.getZ()); }
	inline void setUp( const float& x, const float& y, const float& z ) 
	{ 
		m_Up.setX(x); 
		m_Up.setY(y);
		m_Up.setZ(z);
	}

	inline Vec3 getLeft( void )  { return m_Up.cross(getDir()); }
	inline Vec3 getRight( void ) { return getDir().cross(m_Up); }

	inline float getFOV( void ) const { return m_FOV; }
	inline void setFOV( const float& fov )
	{ 
		m_FOV = fov;
		m_ProjUpdated = true;
	}

	inline void setAspect( const float& width, const float& height ) 
	{ 
		m_AspectWidth = width;
		m_AspectHeight = height;
		m_ProjUpdated = true; 
	}

	void changePitch( const float& amount );
	void changeYaw( const float& amount );

	inline float getSpeed( void ) const { return m_Speed; }
	inline void setSpeed( const float& speed ) { m_Speed = speed; }
	inline void increaseSpeed( const float& amount ) { m_Speed += amount; }
	inline void decreaseSpeed( const float& amount ) { m_Speed -= amount; }

	void setPerspective( const float& fov, const float& width, const float& height, const float& vNear, const float& vFar );

	Mat4 getViewMatrix( void );
	Mat4 getProjectionMatrix( void );

	void moveForward ( const float& amount );
	void moveBackward( const float& amount );
	void moveLeft    ( const float& amount );
	void moveRight   ( const float& amount );

	inline void moveForward ( void ) { moveForward(m_Speed); }
	inline void moveBackward( void ) { moveBackward(m_Speed); }
	inline void moveLeft    ( void ) { moveLeft(m_Speed); }
	inline void moveRight   ( void ) { moveRight(m_Speed); }

private:

	bool			m_ProjUpdated;

	float			m_FOV,
					m_AspectWidth, 
					m_AspectHeight,
					m_Near,
					m_Far,
					m_Pitch,
					m_Yaw,
					m_Speed,
					m_InitialFOV,
					m_InitialNear,
					m_InitialFar,
					m_InitialSpeed;

	Mat4			m_View, 
					m_Proj;

	Vec3			m_Pos,
					m_Dir,
					m_Up,
					m_LookAt,
					m_PosDelta,
					m_InitialPos,
					m_InitialDir,
					m_InitialUp;

	Quat			m_Orient;

};

#endif // WOE_CAMERA_H