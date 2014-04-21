#ifndef WOE_DX_SHADER_MANAGER_H
#define WOE_DX_SHADER_MANAGER_H

#include "BaseShaderManager.h"

#if defined(_WOE_DIRECTX)

#include "DXHeader.h"

#include <d3dcompiler.h>
#include "ShaderTypes.h"

class DXShaderManager :
	public BaseShaderManager
{
public:

	virtual inline string getClassName( void ) const { return "DX Shader Manager"; }

	bool loadShaderFromFile( const string& filename, const ShaderTypes& type );

	ID3D11VertexShader* mp_VertexShader;
	ID3D11PixelShader*  mp_PixelShader;

protected:

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_SHADER_MANAGER_H