#ifndef WOE_SHADER_DATA_H
#define WOE_SHADER_DATA_H

#include "Matrix.h"
#include "Vector.h"

struct FrameShaderData
{
public:

	Mat4 View;
	Mat4 Proj;
	double ElapsedTime;

};

struct EntityShaderData
{
public:

	Mat4 Model;
	Mat4 ModelViewProj;

};

struct VertexShaderData
{
public:

	Vec3 Position;
	Vec3 Normal;
	Vec2 UVCoord;
	Vec4 Color;

};

#endif // WOE_SHADER_DATA_H