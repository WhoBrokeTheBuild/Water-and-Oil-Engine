#ifndef WOE_BASE_MESH_H
#define WOE_BASE_MESH_H

#include <Arc/ManagedObject.h>

#include <Arc/ArrayList.h>

#include "ShaderData.h"
#include "PrimitiveTypes.h"

using Arc::ManagedObject;
using Arc::ArrayList;

class BaseMesh
	: public ManagedObject
{
public:

	inline BaseMesh( void ) 
		: m_VertexCount(0),
		  m_IndexCount(0)
	{ }

	virtual bool setData( const PrimitiveTypes& type, const VertexShaderData* pVertexData, const unsigned int& count, const unsigned int* pIndexes, const int& indexCount  ) = 0;

	inline bool setData( const PrimitiveTypes& type, const ArrayList<VertexShaderData>& vertexData, const ArrayList<unsigned int>& indexes )
	{
		if (vertexData.isEmpty() | indexes.isEmpty())
			return false;
		return setData(type, (const VertexShaderData*)&vertexData[0], vertexData.getSize(), (const unsigned int*)indexes[0], indexes.getSize());
	}

	virtual void render( void ) = 0;

	virtual PrimitiveTypes getPrimitiveType( void ) const = 0;

	virtual inline unsigned int getVertexCount( void ) const { return m_VertexCount; };

	virtual inline unsigned int getIndexCount( void ) const { return m_IndexCount; };

protected:

	unsigned int		m_VertexCount,
						m_IndexCount;

};

#endif // WOE_BASE_MESH_H