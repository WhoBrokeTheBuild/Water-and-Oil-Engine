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

	Vec2 v2_1;
	Vec2 v2_2(1.0f, 2.0f);
	Vec2 v2_3(v2_2);
	Vec2 v2_4(3.0f);

	v2_4.normalize();
	v2_1.length();
	v2_4.lengthSquared();

	Vec3 v3_1;
	Vec3 v3_2(1.0f, 2.0f, 3.0f);
	Vec3 v3_3(v3_2);
	Vec3 v3_4(3.0f);

	v3_1.setX(4.0f);
	v3_1.setY(v3_1.getY() + 2.0f);
	v3_2.addX(2.0f);
	v3_2.subX(4.0f);

	v3_4.normalize();
	v3_3.dot(v3_1);
	v3_1.length();
	v3_3.cross(v3_1);
	v3_4.lengthSquared();

	Vec4 v4_1;
	Vec4 v4_2(1.0f, 2.0f, 3.0f, 4.0f);
	Vec4 v4_3(v4_2);
	Vec4 v4_4(3.0f);

	v4_4.normalize();
	v4_3.dot(v4_1);
	v4_1.length();
	v4_4.lengthSquared();

	Mat3 m3_1;
	Mat3 m3_2(m3_1);

	Mat4 m4_1;
	Mat4 m4_2(m4_1);

	Mat4 lookAt_1 = MathHelper::LookAt(Vec3::ZERO, Vec3::ONE, Vec3(0.0f, 1.0f, 0.0f));

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

	mp_GraphicsSystem->endRender();
}
