#ifndef WOE_DX_GRAPHICS_SYSTEM_H
#define WOE_DX_GRAPHICS_SYSTEM_H

#include "BaseGraphicsSystem.h"

class DXGraphicsSystem :
	public BaseGraphicsSystem
{
public:

	DXGraphicsSystem( int width, int height, string title );

	virtual ~DXGraphicsSystem( void );

protected:

};

#endif // WOE_DX_GRAPHICS_SYSTEM_H