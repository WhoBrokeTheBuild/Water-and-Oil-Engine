#include "DXShaderManager.h"

#if defined(_WOE_DIRECTX)

#include "Log.h"
#include "Game.h"
#include "GraphicsSystem.h"

#include <iostream>
#include <fstream>

bool DXShaderManager::loadShaderProgram( const string& name, const ArrayList<ShaderInfo> shaders )
{
	DXShaderProgram program;
	for (unsigned int i = 0; i < shaders.getSize(); ++i)
	{
		const ShaderInfo& shader = shaders[i];

		switch (shader.Type)
		{
		case WOE_SHADER_TYPE_VERTEX:

			program.pVertexShader = (ID3D11VertexShader*)loadVertexShaderFromFile(name);

			break;
		case WOE_SHADER_TYPE_FRAGMENT:

			program.pPixelShader = (ID3D11PixelShader*)loadPixelShaderFromFile(name);

			break;
		}
	}
}

bool DXShaderManager::hasShaderProgram( const string& name )
{
}

bool DXShaderManager::useShaderProgram( const string& name )
{
	DXShaderProgram& program = m_Programs[name];

	Game::Instance()->getGraphicsSystem()->getDXDeviceContext()->VSSetShader(program.pVertexShader, nullptr, 0 );
	Game::Instance()->getGraphicsSystem()->getDXDeviceContext()->PSSetShader(program.pPixelShader, nullptr, 0 );
}

ID3D11VertexShader* DXShaderManager::loadVertexShaderFromFile( const string& filename )
{
	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

	// Convert filename to wide string
	int filenameLen = (int)filename.length() + 1;
	int newLen = MultiByteToWideChar(CP_ACP, 0, filename.c_str(), filenameLen, 0, 0);
	wchar_t* buf = new wchar_t[filenameLen];
	MultiByteToWideChar(CP_ACP, 0, filename.c_str(), filenameLen, buf, newLen);
	std::wstring wFilename(buf);
	delete[] buf;

#if defined(_WOE_DEBUG)

	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	shaderFlags |= D3DCOMPILE_DEBUG;

#endif // _WOE_DEBUG

	ID3DBlob* pErrorBlob = nullptr;
	ID3DBlob* pOutputBlob = nullptr;
	HRESULT hr;
	hr = D3DCompileFromFile(wFilename.c_str(), nullptr, nullptr, "VS", "vs_4_0", shaderFlags, 0, &pOutputBlob, &pErrorBlob);

	if (FAILED(hr))
	{
		if (pErrorBlob)
		{
			Log::ErrorFmt(getClassName(), "Failed to compile HLSL: %s", reinterpret_cast<const char*>(pErrorBlob->GetBufferPointer()));
			pErrorBlob->Release();
		}
		else
		{
			if (hr == HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND))
			{
				Log::Error(getClassName(), "Failed to compile HLSL, File not found");
			}
			else
			{
				Log::Error(getClassName(), "Failed to compile HLSL, Unknown Error");
			}
		}

		return nullptr;
	}
	if (pErrorBlob)
		pErrorBlob->Release();

	ID3D11VertexShader* pVertexShader = nullptr;
	hr = Game::Instance()->getGraphicsSystem()->getDXDevice()->CreateVertexShader(pOutputBlob->GetBufferPointer(), pOutputBlob->GetBufferSize(), nullptr, &pVertexShader);

	if (FAILED(hr))
	{
		Log::Error(getClassName(), "Failed to create vertex shader");
		pOutputBlob->Release();
		pVertexShader->Release();
		return nullptr;
	}

	ID3D11InputLayout* pVertexLayout = nullptr;

	// Define the input layout
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	UINT numElements = ARRAYSIZE( layout );

	// Create the input layout
	hr = Game::Instance()->getGraphicsSystem()->getDXDevice()->CreateInputLayout(layout, numElements, pOutputBlob->GetBufferPointer(), pOutputBlob->GetBufferSize(), &pVertexLayout);

	pOutputBlob->Release();

	if (FAILED( hr ))
	{
		Log::Error(getClassName(), "Failed to attach vertex shader");
		return nullptr;
	}

	// Set the input layout
	Game::Instance()->getGraphicsSystem()->getDXDeviceContext()->IASetInputLayout(pVertexLayout);

	return pVertexShader;
}

ID3D11PixelShader* DXShaderManager::loadPixelShaderFromFile( const string& filename )
{
	DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

	// Convert filename to wide string
	int filenameLen = (int)filename.length() + 1;
	int newLen = MultiByteToWideChar(CP_ACP, 0, filename.c_str(), filenameLen, 0, 0);
	wchar_t* buf = new wchar_t[filenameLen];
	MultiByteToWideChar(CP_ACP, 0, filename.c_str(), filenameLen, buf, newLen);
	std::wstring wFilename(buf);
	delete[] buf;

#if defined(_WOE_DEBUG)

	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	shaderFlags |= D3DCOMPILE_DEBUG;

#endif // _WOE_DEBUG

	ID3DBlob* pErrorBlob = nullptr;
	ID3DBlob* pOutputBlob = nullptr;
	HRESULT hr;
	hr = D3DCompileFromFile(wFilename.c_str(), nullptr, nullptr, (type == ShaderTypes::WOE_SHADER_TYPE_VERTEX ? "VS" : "PS"), (type == ShaderTypes::WOE_SHADER_TYPE_VERTEX ? "vs_4_0" : "ps_4_0"), shaderFlags, 0, &pOutputBlob, &pErrorBlob);

	if (FAILED(hr))
	{
		if (pErrorBlob)
		{
			Log::ErrorFmt(getClassName(), "Failed to compile HLSL: %s", reinterpret_cast<const char*>(pErrorBlob->GetBufferPointer()));
			pErrorBlob->Release();
		}
		else
		{
			if (hr == HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND))
			{
				Log::Error(getClassName(), "Failed to compile HLSL, File not found");
			}
			else
			{
				Log::Error(getClassName(), "Failed to compile HLSL, Unknown Error");
			}
		}

		return nullptr;
	}
	if (pErrorBlob)
		pErrorBlob->Release();

	ID3D11PixelShader* pPixelShader = nullptr;
	hr = Game::Instance()->getGraphicsSystem()->getDXDevice()->CreatePixelShader(pOutputBlob->GetBufferPointer(), pOutputBlob->GetBufferSize(), nullptr, &pPixelShader);

	if (FAILED(hr))
	{
		Log::Error(getClassName(), "Failed to create vertex shader");
		pOutputBlob->Release();
		pPixelShader->Release();
		return nullptr;
	}

	return pPixelShader;
}

#endif // _WOE_DIRECTX