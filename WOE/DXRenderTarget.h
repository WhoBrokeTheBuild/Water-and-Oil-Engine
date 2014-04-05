#ifndef WOE_DX_RENDER_TARGET_H
#define WOE_DX_RENDER_TARGET_H

#include "BaseRenderTarget.h"

class DXRenderTarget :
	public BaseRenderTarget
{
public:

	virtual inline string getClassName( void ) const { return "DX Render Target"; }

};

#endif // WOE_DX_RENDER_TARGET_H