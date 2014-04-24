#ifndef WOE_DX_SHADER_MANAGER_H
#define WOE_DX_SHADER_MANAGER_H

#include "BaseShaderManager.h"

#if defined(_WOE_DIRECTX)

#include "DXHeader.h"

#include <d3dcompiler.h>
#include "ShaderTypes.h"

struct DXShaderProgram
{
public:

	DXShaderProgram( void )
		: pVertexShader(nullptr),
		  pPixelShader(nullptr)
	{ }

	ID3D11VertexShader* pVertexShader;
	ID3D11PixelShader*  pPixelShader;
};

class DXShaderManager :
	public BaseShaderManager
{
public:

	virtual inline string getClassName( void ) const { return "DX Shader Manager"; }

	virtual bool loadShaderProgram( const string& name, const ArrayList<ShaderInfo> shaders );

	virtual bool hasShaderProgram( const string& name );
	virtual bool useShaderProgram( const string& name );

protected:

	
	ID3D11VertexShader* loadVertexShaderFromFile( const string& filename );
	ID3D11PixelShader* loadPixelShaderFromFile( const string& filename );

	Map<string, DXShaderProgram> m_Programs;

};

#endif // _WOE_DIRECTX

#endif // WOE_DX_SHADER_MANAGER_H