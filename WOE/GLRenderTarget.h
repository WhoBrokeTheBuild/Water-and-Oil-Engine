#ifndef WOE_GL_RENDER_TARGET_H
#define WOE_GL_RENDER_TARGET_H

#include "BaseRenderTarget.h"

#if defined(_WOE_OPENGL)

class GLRenderTarget :
	public BaseRenderTarget
{
public:

	GLRenderTarget( void );

	virtual inline string getClassName( void ) const { return "GL Render Target"; }

	virtual void render( Entity* entity );

protected:

	GLuint		m_FrameDataBuffer,
				m_EntityDataBuffer;

};

#endif // _WOE_OPENGL

#endif // WOE_GL_RENDER_TARGET_H