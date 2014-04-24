#ifndef WOE_BASE_SHADER_MANAGER_H
#define WOE_BASE_SHADER_MANAGER_H

#include <Arc/ManagedObject.h>

#include <Arc/ArrayList.h>
#include "ShaderInfo.h"

using Arc::ManagedObject;
using Arc::ArrayList;

class BaseShaderManager :
	public ManagedObject
{
public:

	virtual bool loadShaderProgram( const string& name, const ArrayList<ShaderInfo> shaders ) = 0;

	virtual bool hasShaderProgram( const string& name ) = 0;

	virtual bool useShaderProgram( const string& name ) = 0;

};

#endif // WOE_BASE_SHADER_MANAGER_H