#include "DXShaderManager.h"

#include "Log.h"
#include "Game.h"
#include "GraphicsSystem.h"

#include <iostream>
#include <fstream>

bool DXShaderManager::loadShaderFromFile( const string& filename, const ShaderTypes& type )
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
	hr = D3DCompileFromFile(wFilename.c_str(), nullptr, nullptr, "main", (type == ShaderTypes::WOE_SHADER_TYPE_VERTEX ? "vs_4_0" : "ps_4_0"), shaderFlags, 0, &pOutputBlob, &pErrorBlob);

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

		return false;
	}
	if (pErrorBlob)
		pErrorBlob->Release();

	if (type == ShaderTypes::WOE_SHADER_TYPE_VERTEX)
	{
		ID3D11VertexShader* pVertexShader = nullptr;
		hr = Game::Instance()->getGraphicsSystem()->getDXDevice()->CreateVertexShader(pOutputBlob->GetBufferPointer(), pOutputBlob->GetBufferSize(), nullptr, &pVertexShader);

		if (FAILED(hr))
		{
			Log::Error(getClassName(), "Failed to create vertex shader");
			pOutputBlob->Release();
			pVertexShader->Release();
			return false;
		}
	}
	else
	{
		ID3D11PixelShader* pPixelShader = nullptr;
		hr = Game::Instance()->getGraphicsSystem()->getDXDevice()->CreatePixelShader(pOutputBlob->GetBufferPointer(), pOutputBlob->GetBufferSize(), nullptr, &pPixelShader);

		if (FAILED(hr))
		{
			Log::Error(getClassName(), "Failed to create vertex shader");
			pOutputBlob->Release();
			pPixelShader->Release();
			return false;
		}
	}

	pOutputBlob->Release();

	return true;
}
