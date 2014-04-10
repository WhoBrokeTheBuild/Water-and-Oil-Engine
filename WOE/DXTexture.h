#ifndef WOE_DX_TEXTURE_H
#define WOE_DX_TEXTURE_H

#if defined(_WOE_DIRECTX)

#include "BaseTexture.h"

#include "GLHeader.h"

class DXTexture
	: public BaseTexture
{
public:

	DXTexture( const string& filename )
		: BaseTexture(filename)
	{ }

	virtual bool loadFile( const string& filename );

protected:

	DXTexture( const unsigned int& width, const unsigned int& height )
		: BaseTexture(width, height, "")
	{ }

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_TEXTURE_H