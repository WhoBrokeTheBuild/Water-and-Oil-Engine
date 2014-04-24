#ifndef WOE_GL_MESH_H
#define WOE_GL_MESH_H

#include "BaseMesh.h"

#if defined(_WOE_OPENGL)

#include <Arc/ArrayList.h>

#include "GLHeader.h"
#include "PrimitiveTypes.h"

using namespace Arc;

class ResourceManager;

class GLMesh :
	public BaseMesh
{

	friend class ResourceManager;

public:

	inline GLMesh( void )
		: BaseMesh()
	{ }

	virtual ~GLMesh( void );

	virtual inline string getClassName( void ) const { return "GL Mesh"; }

	virtual bool setData( const PrimitiveTypes& type, const VertexShaderData* pVertexData, const unsigned int& count, const unsigned int* pIndexes, const int& indexCount );

	virtual void render( void );

	virtual PrimitiveTypes getPrimitiveType( void ) const;

private:

	virtual void setPrimitiveType( const PrimitiveTypes& type );

	GLenum		m_PrimitiveType;

	GLuint		m_IndexBuffer,
				m_VertexBuffer;

};

#endif // _WOE_OPENGL

#endif // WOE_GL_MESH_H