#ifndef WOE_GL_SHADER_MANAGER_H
#define WOE_GL_SHADER_MANAGER_H

#include "BaseShaderManager.h"

class GLShaderManager :
	public BaseShaderManager
{
public:

	virtual inline string getClassName( void ) const { return "DX Shader Manager"; }

};

#endif // WOE_GL_SHADER_MANAGER_H