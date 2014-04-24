#include "GLShaderManager.h"

#if defined(_WOE_OPENGL)

#include "Log.h"
#include <fstream>

bool GLShaderManager::loadShaderProgram( const string& name, const ArrayList<ShaderInfo> shaders )
{
	ArrayList<GLuint> shaderIDs;
	for (unsigned int i = 0; i < shaders.getSize(); ++i)
	{
		const ShaderInfo& shader = shaders[i];
		GLenum shaderType;

		switch (shader.Type)
		{
		case WOE_SHADER_TYPE_VERTEX:

			shaderType = GL_VERTEX_SHADER;

			break;
		case WOE_SHADER_TYPE_FRAGMENT:

			shaderType = GL_FRAGMENT_SHADER;

			break;
		}

		shaderIDs.add(loadShaderFromFile(shader.Filename, shaderType));
	}

	GLuint program = glCreateProgram();

	for (unsigned int i = 0; i < shaderIDs.getSize(); ++i)
	{
		glAttachShader(program, shaderIDs[i]);
	}

	glLinkProgram(program);

	GLint programLinked = GL_FALSE;
	glGetProgramiv(program, GL_LINK_STATUS, &programLinked);

	if (programLinked != GL_TRUE)
	{
		Log::ErrorFmt(getClassName(), "Failed to link program %d\n", program);
		printProgramLog(program);
		glDeleteProgram(program);
		program = 0;
	}

	for (unsigned int i = 0; i < shaderIDs.getSize(); ++i)
		glDeleteShader(shaderIDs[i]);

	if (program == 0)
		return false;

	m_Programs.add(name, program);

	return true;
}

bool GLShaderManager::hasShaderProgram( const string& name )
{
	return m_Programs.containsKey(name);
}

bool GLShaderManager::useShaderProgram( const string& name )
{
	if ( ! m_Programs.containsKey(name))
	{
		glUseProgram(0);
		return false;
	}

	glUseProgram(m_Programs[name]);
	return true;
}

GLuint GLShaderManager::loadShaderFromFile( const string& filename, const GLenum& type )
{
	GLuint shader = 0;
	string shaderString;
	std::ifstream file(filename);

	if (file)
	{
		shaderString.assign( (std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>() );
		shader = glCreateShader(type);

		const GLchar* shaderSource = shaderString.c_str();

		glShaderSource(shader, 1, (const GLchar**)&shaderSource, NULL);
		glCompileShader(shader);

		GLint shaderCompiled = GL_FALSE;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompiled);

		if (shaderCompiled != GL_TRUE)
		{
			Log::ErrorFmt(getClassName(), "Failed to compile shader %d \"%s\"", shader, filename.c_str());
			printShaderLog(shader);
			glDeleteShader(shader);
			return 0;
		}
	}
	else
	{
		Log::ErrorFmt(getClassName(), "Unable to open file \"%s\"", filename.c_str());
		return 0;
	}

	return shader;
}

void GLShaderManager::printProgramLog( const GLuint& program )
{
	if( glIsProgram( program ) )
	{
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		glGetProgramiv( program, GL_INFO_LOG_LENGTH, &maxLength );

		char* infoLog = new char[ maxLength ];

		glGetProgramInfoLog( program, maxLength, &infoLogLength, infoLog );
		if( infoLogLength > 0 )
		{
			Log::ErrorFmt(getClassName(), "Log for Program %d:\n%s", program, infoLog);
		}

		delete[] infoLog;
	}
	else
	{
		Log::ErrorFmt(getClassName(), "Cannot print program log, %d is not a program", program);
	}
}

void GLShaderManager::printShaderLog( const GLuint& shader )
{
	if( glIsShader( shader ) )
	{
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &maxLength );

		char* infoLog = new char[ maxLength ];

		glGetShaderInfoLog( shader, maxLength, &infoLogLength, infoLog );
		if( infoLogLength > 0 )
		{
			Log::ErrorFmt(getClassName(), "Log for Shader %d:\n%s", shader, infoLog);
		}

		delete[] infoLog;
	}
	else
	{
		Log::ErrorFmt(getClassName(), "Cannot print shader log, %d is not a shader", shader);
	}
}

#endif // _WOE_OPENGL