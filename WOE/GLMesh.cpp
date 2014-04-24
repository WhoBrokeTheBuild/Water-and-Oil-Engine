#include "GLMesh.h"

GLMesh::~GLMesh( void )
{
}

bool GLMesh::setData( const PrimitiveTypes& type, const VertexShaderData* pVertexData, const unsigned int& vertexCount, const unsigned int* pIndexes, const int& indexCount )
{
	setPrimitiveType(type);
	m_VertexCount = vertexCount;
	m_IndexCount = indexCount;

	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	//glBufferData()

	glBufferData(GL_UNIFORM_BUFFER, sizeof(VertexShaderData), NULL, GL_STATIC_COPY);

	return true;
}

void GLMesh::render( void )
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	//glDrawElements(m_PrimitiveType, m_IndexCount, GL_UNSIGNED_INT, 0);
}

PrimitiveTypes GLMesh::getPrimitiveType( void ) const
{
	switch (m_PrimitiveType)
	{
	case GL_TRIANGLES:

		return WOE_PRIMITIVE_TYPE_TRIANGLE;

		break;
	case GL_TRIANGLE_STRIP:

		return WOE_PRIMITIVE_TYPE_TRIANGLE_STRIP;

		break;
	case GL_QUADS:

		return WOE_PRIMITIVE_TYPE_QUAD;

		break;
	}

	return WOE_INVALID_PRIMITIVE_TYPE;
}

void GLMesh::setPrimitiveType( const PrimitiveTypes& type )
{
	switch (type)
	{
	case WOE_PRIMITIVE_TYPE_TRIANGLE:

		m_PrimitiveType = GL_TRIANGLES;

		break;
	case WOE_PRIMITIVE_TYPE_TRIANGLE_STRIP:

		m_PrimitiveType = GL_TRIANGLE_STRIP;

		break;
	case WOE_PRIMITIVE_TYPE_QUAD:

		m_PrimitiveType = GL_QUADS;

		break;
	}
}
