#include "GLRenderTarget.h"

#if defined(_WOE_OPENGL)

GLRenderTarget::GLRenderTarget( void )
	: m_FrameDataBuffer(0),
	  m_EntityDataBuffer(0)
{
	glGenBuffers(1, &m_FrameDataBuffer);
	glBindBuffer(GL_UNIFORM_BUFFER, m_FrameDataBuffer);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(FrameShaderData), NULL, GL_STATIC_COPY);

	glGenBuffers(1, &m_EntityDataBuffer);
	glBindBuffer(GL_UNIFORM_BUFFER, m_EntityDataBuffer);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(EntityShaderData), NULL, GL_STATIC_COPY);
}

void GLRenderTarget::render( Entity* entity )
{
}

#endif // _WOE_OPENGL