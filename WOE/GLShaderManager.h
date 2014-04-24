#ifndef WOE_GL_SHADER_MANAGER_H
#define WOE_GL_SHADER_MANAGER_H

#include "BaseShaderManager.h"

#if defined(_WOE_OPENGL)

#include "GLHeader.h"
#include "ShaderInfo.h"

#include <Arc/Map.h>

using Arc::Map;

class GLShaderManager :
	public BaseShaderManager
{
public:

	virtual inline string getClassName( void ) const { return "GL Shader Manager"; }

	virtual bool loadShaderProgram( const string& name, const ArrayList<ShaderInfo> shaders );

	virtual bool hasShaderProgram( const string& name );
	virtual bool useShaderProgram( const string& name );

protected:

	GLuint loadShaderFromFile( const string& filename, const GLenum& type );

	void printProgramLog( const GLuint& program );
	void printShaderLog( const GLuint& shader );

	Map<string, GLuint>		m_Programs;

};

#endif // _WOE_OPENGL

#endif // WOE_GL_SHADER_MANAGER_H