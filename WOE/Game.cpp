#include "Game.h"

#include "GameTime.h"
#include "Timer.h"
#include "Log.h"

#include <iostream>
#include <fstream>
#include "MathHelper.h"

Game* Game::sp_Instance = nullptr;
Args* Game::sp_Args     = nullptr;

const EventType Game::EVENT_UPDATE = "game.update";
const EventType Game::EVENT_RENDER = "game.render";
const EventType Game::EVENT_EXIT   = "game.exit";

void Game::Create( Args* pArgs )
{
	delete sp_Instance;
	sp_Instance = nullptr;

	Game::sp_Args = pArgs;
	New Game();
}

Game* Game::Instance( void )
{
	return sp_Instance;
}

void Game::Destroy( void )
{
	delete sp_Instance;
	sp_Instance = nullptr;
}

Args* Game::GetArgs(void)
{
	return sp_Args;
}

#include "DXHeader.h"

using namespace DirectX;

struct SimpleVertex
{
	XMFLOAT3 Pos;
};

Game::Game( void )
{
	Log::Info(getClassName(), "Starting Up");

	sp_Instance = this;

	mp_GraphicsSystem = New GraphicsSystem(800, 600, "Testing", false);
	mp_GraphicsSystem->setClearColor(Color("00AAAA"));

	mp_InputSystem = New InputSystem();

	addEventListener(EVENT_EXIT, this, &Game::evtExit);


	mp_GraphicsSystem->getShaderManager()->loadShaderFromFile("../Shaders/HLSL/Test_VS.fx", ShaderTypes::WOE_SHADER_TYPE_VERTEX);
	mp_GraphicsSystem->getShaderManager()->loadShaderFromFile("../Shaders/HLSL/Test_PS.fx", ShaderTypes::WOE_SHADER_TYPE_PIXEL);

	ID3D11Buffer*           g_pVertexBuffer = nullptr;

	// Create vertex buffer
	SimpleVertex vertices[] =
	{
		XMFLOAT3( 0.0f, 0.5f, 0.5f ),
		XMFLOAT3( 0.5f, -0.5f, 0.5f ),
		XMFLOAT3( -0.5f, -0.5f, 0.5f ),
	};
	D3D11_BUFFER_DESC bd;
	ZeroMemory( &bd, sizeof(bd) );
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof( SimpleVertex ) * 3;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory( &InitData, sizeof(InitData) );
	InitData.pSysMem = vertices;
	HRESULT hr = getGraphicsSystem()->getDXDevice()->CreateBuffer( &bd, &InitData, &g_pVertexBuffer );
	if( FAILED( hr ) )
	{
		Log::Error(getClassName(), "Failed to run directx shit");
		return;
	}

	// Set vertex buffer
	UINT stride = sizeof( SimpleVertex );
	UINT offset = 0;
	getGraphicsSystem()->getDXDeviceContext()->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );

	// Set primitive topology
	getGraphicsSystem()->getDXDeviceContext()->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );


	Log::Info(getClassName(), "Finished");
}

Game::~Game( void )
{
	Log::Info(getClassName(), "Shutting Down");

	delete mp_InputSystem;
	delete mp_GraphicsSystem;

	Log::Info(getClassName(), "Finished");
}

void Game::start( void )
{
	Log::Info(getClassName(), "Starting Game Loop");

	mp_GameTime = New GameTime();

	Timer fpsTimer;
	fpsTimer.start();

	double frameElapsedTime;

	while (m_Running)
	{
		update();
		render();

		fpsTimer.sleepUntilElapsed(mp_GameTime->getFrameDelayMS());

		frameElapsedTime = fpsTimer.getElapsedMilli();

		mp_GameTime->updateTime(frameElapsedTime);

		fpsTimer.start();
	}

	delete mp_GameTime;

	Log::Info(getClassName(), "Stopping Game Loop");
}

void Game::update(void)
{
	mp_GraphicsSystem->update(mp_GameTime);
	mp_InputSystem->update(mp_GameTime);
}

void Game::render(void)
{
	mp_GraphicsSystem->beginRender();

	getGraphicsSystem()->getDXDeviceContext()->VSSetShader( getGraphicsSystem()->getShaderManager()->mp_VertexShader, nullptr, 0 );
	getGraphicsSystem()->getDXDeviceContext()->PSSetShader( getGraphicsSystem()->getShaderManager()->mp_PixelShader, nullptr, 0 );
	getGraphicsSystem()->getDXDeviceContext()->Draw( 3, 0 );

	mp_GraphicsSystem->endRender();
}
