#ifndef WOE_GL_TEXTURE_H
#define WOE_GL_TEXTURE_H

#if defined(_WOE_OPENGL)

#include "BaseTexture.h"

#include "GLHeader.h"

class GLTexture
	: public BaseTexture
{
public:

	GLTexture( const string& filename )
		: BaseTexture(filename),
		  m_TexID(INVALID_GL_TEXTURE_ID)
	{ }

	inline ~GLTexture( void )
	{
		if (m_TexID)
			glDeleteTextures(1, &m_TexID);
	}

	virtual bool loadFile( const string& filename );

protected:

	GLTexture( const GLuint& texID, const unsigned int& width, const unsigned int& height )
		: BaseTexture(width, height, ""),
		  m_TexID(texID)
	{ }

	GLuint		m_TexID;

};

#endif // _WOE_OPENGL

#endif // WOE_GL_TEXTURE_H