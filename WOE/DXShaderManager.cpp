#include "DXShaderManager.h"

#if defined(_WOE_DIRECTX)

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

		return false;
	}
	if (pErrorBlob)
		pErrorBlob->Release();

	if (type == ShaderTypes::WOE_SHADER_TYPE_VERTEX)
	{
		mp_VertexShader = nullptr;
		hr = Game::Instance()->getGraphicsSystem()->getDXDevice()->CreateVertexShader(pOutputBlob->GetBufferPointer(), pOutputBlob->GetBufferSize(), nullptr, &mp_VertexShader);

		if (FAILED(hr))
		{
			Log::Error(getClassName(), "Failed to create vertex shader");
			pOutputBlob->Release();
			mp_VertexShader->Release();
			return false;
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
			return false;
		}

		// Set the input layout
		Game::Instance()->getGraphicsSystem()->getDXDeviceContext()->IASetInputLayout(pVertexLayout);
	}
	else
	{
		mp_PixelShader = nullptr;
		hr = Game::Instance()->getGraphicsSystem()->getDXDevice()->CreatePixelShader(pOutputBlob->GetBufferPointer(), pOutputBlob->GetBufferSize(), nullptr, &mp_PixelShader);

		if (FAILED(hr))
		{
			Log::Error(getClassName(), "Failed to create vertex shader");
			pOutputBlob->Release();
			mp_PixelShader->Release();
			return false;
		}
	}

	return true;
}

#endif // _WOE_DIRECTX