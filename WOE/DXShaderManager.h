#ifndef WOE_DX_SHADER_MANAGER_H
#define WOE_DX_SHADER_MANAGER_H

#include "BaseShaderManager.h"

class DXShaderManager :
	public BaseShaderManager
{
public:

	virtual inline string getClassName( void ) const { return "DX Shader Manager"; }

};

#endif // WOE_DX_SHADER_MANAGER_H