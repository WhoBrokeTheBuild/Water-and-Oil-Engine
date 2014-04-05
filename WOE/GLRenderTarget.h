#ifndef WOE_GL_RENDER_TARGET_H
#define WOE_GL_RENDER_TARGET_H

#include "BaseRenderTarget.h"

class GLRenderTarget :
	public BaseRenderTarget
{
public:

	virtual inline string getClassName( void ) const { return "GL Render Target"; }

};

#endif // WOE_GL_RENDER_TARGET_H