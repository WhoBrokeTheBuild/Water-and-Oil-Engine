#ifndef WOE_BASE_RENDER_TARGET_H
#define WOE_BASE_RENDER_TARGET_H

#include <Arc/ManagedObject.h>

#include "ShaderData.h"
#include "Entity.h"

using Arc::ManagedObject;

class BaseRenderTarget :
	public ManagedObject
{
public:

	virtual void render( Entity* entity ) = 0;

protected:

	FrameShaderData		m_FrameShaderData;

	EntityShaderData	m_EntityShaderData;

};

#endif // WOE_BASE_RENDER_TARGET_H