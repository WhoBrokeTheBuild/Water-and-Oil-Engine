#include "Game.h"

#include "GameTime.h"
#include "Timer.h"

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
	sp_Instance = New Game();
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
	mp_GraphicsSystem = New GraphicsSystem(1920, 1080, "Testing", false);
	mp_GraphicsSystem->setClearColor(Color(0, 170, 170));

	addEventListener(EVENT_EXIT, this, &Game::evtExit);
	mp_GraphicsSystem->addEventListener(EVENT_EXIT, this, &Game::evtExit);
}

Game::~Game( void )
{
	delete mp_GraphicsSystem;
}

void Game::start( void )
{
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
}

void Game::update(void)
{
	mp_GraphicsSystem->update(mp_GameTime);
}

void Game::render(void)
{
	mp_GraphicsSystem->beginRender();

	mp_GraphicsSystem->endRender();
}
