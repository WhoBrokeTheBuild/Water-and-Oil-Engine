#include "Game.h"

#include "GameTime.h"
#include "Timer.h"

Game* Game::s_Instance = nullptr;

const EventType Game::EVENT_UPDATE = "game.update";
const EventType Game::EVENT_RENDER = "game.render";
const EventType Game::EVENT_EXIT   = "game.exit";

Game* Game::Instance( void )
{
	if ( ! s_Instance)
		s_Instance = New Game();

	return s_Instance;
}

void Game::Destroy( void )
{
	delete s_Instance;
	s_Instance = nullptr;
}

Game::Game( void )
{
	mp_GraphicsSystem = New GraphicsSystem(640, 480, "Testing");
	mp_GraphicsSystem->setClearColor(Color("888888"));

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
