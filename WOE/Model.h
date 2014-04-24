#ifndef WOE_MODEL_H
#define WOE_MODEL_H

#include <Arc/ManagedObject.h>

#include <Arc/ArrayList.h>

#include "Mesh.h"

using Arc::ManagedObject;
using Arc::ArrayList;

class Model
	: public ManagedObject
{
public:

	virtual inline string getClassName( void ) const { return "Model"; }

	inline void addMesh( Mesh* pMesh ) { m_Meshes.add(pMesh); }

	inline bool hasMesh( Mesh* pMesh ) { return m_Meshes.contains(pMesh); }

	inline bool removeMesh( Mesh* pMesh ) { return m_Meshes.remove(pMesh); }

	inline void clearMeshes( void ) { m_Meshes.clear(); }

	void render( void );
	 
protected:

	ArrayList<Mesh*> m_Meshes;

};

#endif // WOE_MODEL_H