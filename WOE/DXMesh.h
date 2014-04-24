#ifndef WOE_DX_MESH_H
#define WOE_DX_MESH_H

#include "BaseMesh.h"

#if defined(_WOE_DIRECTX)

#include <Arc/ArrayList.h>

#include "DXHeader.h"

using namespace Arc;

class ResourceManager;

class DXMesh :
	public BaseMesh
{

	friend class ResourceManager;

public:

	inline DXMesh( void )
	{ }

	virtual ~DXMesh( void );

	virtual inline string getClassName( void ) const { return "DX Mesh"; }

private:

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_MESH_H