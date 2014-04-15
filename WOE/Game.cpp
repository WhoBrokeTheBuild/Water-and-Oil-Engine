#include "Game.h"

#include "GameTime.h"
#include "Timer.h"
#include "Log.h"

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
	mp_GraphicsSystem->setClearColor(Color(0, 170, 170));

	mp_InputSystem = New InputSystem();

	addEventListener(EVENT_EXIT, this, &Game::evtExit);

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
