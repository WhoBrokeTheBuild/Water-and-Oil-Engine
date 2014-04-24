#ifndef WOE_SHADER_DATA_H
#define WOE_SHADER_DATA_H

#include "Matrix.h"
#include "Vector.h"

struct FrameShaderData
{
public:

	inline FrameShaderData( const Mat4& view = Mat4(), const Mat4& proj = Mat4() )
		: View(view),
		  Proj(proj)
	{ }

	Mat4 View;
	Mat4 Proj;
	double ElapsedTime;

};

struct EntityShaderData
{
public:

	inline EntityShaderData( const Mat4& model = Mat4(), const Mat4& mvp = Mat4() )
		: Model(model),
		  ModelViewProj(mvp)
	{ }

	Mat4 Model;
	Mat4 ModelViewProj;

};

struct VertexShaderData
{
public:

	inline VertexShaderData( const Vec3& pos = Vec3::ZERO, const Vec3& normal = Vec3::ZERO, const Vec2& uvcoord = Vec2::ZERO, const Vec4& color = Vec4(0.0f, 0.0f, 0.0f, 1.0f) )
		: Position(pos),
		  Normal(normal),
		  UVCoord(uvcoord),
		  Color(color)
	{ }

	Vec3 Position;

	float pad1;

	Vec3 Normal;

	float pad2;

	Vec2 UVCoord;

	float pad3;
	float pad4;

	Vec4 Color;

};

#endif // WOE_SHADER_DATA_H