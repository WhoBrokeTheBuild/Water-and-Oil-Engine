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

Game::Game( void )
{
	Log::Info(getClassName(), "Starting Up");

	sp_Instance = this;

	mp_GraphicsSystem = New GraphicsSystem(800, 600, "Testing", false);
	mp_GraphicsSystem->setClearColor(Color("00AAAA"));

	mp_InputSystem = New InputSystem();

	addEventListener(EVENT_EXIT, this, &Game::evtExit);

	mp_TestEntity = New Entity(Vec3::ZERO);

	ArrayList<ShaderInfo> shaders;

#if defined(_WOE_OPENGL)

	shaders.add(ShaderInfo("../Shaders/GLSL/Test.vs.glsl", ShaderTypes::WOE_SHADER_TYPE_VERTEX));
	shaders.add(ShaderInfo("../Shaders/GLSL/Test.fs.glsl", ShaderTypes::WOE_SHADER_TYPE_PIXEL));

#elif defined(_WOE_DIRECTX)

	shaders.add(ShaderInfo("../Shaders/HLSL/Test_VS.fx", ShaderTypes::WOE_SHADER_TYPE_VERTEX));
	shaders.add(ShaderInfo("../Shaders/HLSL/Test_PS.fx", ShaderTypes::WOE_SHADER_TYPE_PIXEL));

#endif // _WOE_DIRECTX

	getGraphicsSystem()->getShaderManager()->loadShaderProgram("test", shaders);

	// Create vertex buffer

	//D3D11_BUFFER_DESC bd;
	//ZeroMemory( &bd, sizeof(bd) );
	//bd.Usage = D3D11_USAGE_DEFAULT;
	//bd.ByteWidth = sizeof( SimpleVertex ) * 3;
	//bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	//bd.CPUAccessFlags = 0;
	//D3D11_SUBRESOURCE_DATA InitData;
	//ZeroMemory( &InitData, sizeof(InitData) );
	//InitData.pSysMem = vertices;
	//HRESULT hr = getGraphicsSystem()->getDXDevice()->CreateBuffer( &bd, &InitData, &g_pVertexBuffer );
	//if( FAILED( hr ) )
	//{
	//	Log::Error(getClassName(), "Failed to run DirectX shit");
	//	return;
	//}
	//
	//// Set vertex buffer
	//UINT stride = sizeof( SimpleVertex );
	//UINT offset = 0;
	//getGraphicsSystem()->getDXDeviceContext()->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );
	//
	//// Set primitive topology
	//getGraphicsSystem()->getDXDeviceContext()->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );
	//// Render
	//getGraphicsSystem()->getDXDeviceContext()->Draw( 3, 0 );


	Log::Info(getClassName(), "Finished");
}

Game::~Game( void )
{
	Log::Info(getClassName(), "Shutting Down");

	delete mp_TestEntity;

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
	getGraphicsSystem()->update(mp_GameTime);
	getInputSystem()->update(mp_GameTime);
}

void Game::render(void)
{
	getGraphicsSystem()->beginRender();

	getGraphicsSystem()->getShaderManager()->useShaderProgram("test");


	VertexShaderData vertices[] =
	{
		VertexShaderData(Vec3( 0.0f,  0.5f, 0.5f)), // top
		VertexShaderData(Vec3( 0.5f, -0.5f, 0.5f)), // bottom right
		VertexShaderData(Vec3(-0.5f, -0.5f, 0.5f))  // bottom left
	};

	unsigned int indexes[] = { 0, 1, 2 };

	Mesh mesh;
	mesh.setData(PrimitiveTypes::WOE_PRIMITIVE_TYPE_TRIANGLE, vertices, 3, indexes, 3);

	mesh.render();
	

	getGraphicsSystem()->endRender();

	system("PAUSE");
}
