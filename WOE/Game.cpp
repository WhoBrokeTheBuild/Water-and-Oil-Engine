#include "Game.h"

#include "GameTime.h"
#include "Timer.h"

Game* Game::s_Instance = nullptr;

const EventType Game::EVENT_UPDATE_START	= "game.updateStart";
const EventType Game::EVENT_UPDATE			= "game.update";
const EventType Game::EVENT_UPDATE_END		= "game.updateEnd";
const EventType Game::EVENT_RENDER_START	= "game.renderStart";
const EventType Game::EVENT_RENDER			= "game.render";
const EventType Game::EVENT_RENDER_END		= "game.renderEnd";
const EventType Game::EVENT_EXIT			= "game.exit";

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
}

Game::~Game( void )
{
	delete mp_GraphicsSystem;
}

void Game::start( void )
{
	//while( ! glfwWindowShouldClose(mp_Window) )
	//{
	//	const float updateInt = 1.0f / 60.0f;
	//	static float updateTimer = 0.0f;
	//
	//	double currTime = glfwGetTime();
	//	float deltaTime = (float)(currTime - m_LastFrameTime);
	//	m_LastFrameTime = currTime;
	//
	//	updateTimer += deltaTime;
	//
	//	if (updateTimer >= updateInt)
	//	{
	//		updateTimer = 0.0f;
	//		deltaTime = updateInt; // Actual time since last update/render
	//
	//		update(deltaTime);
	//		render();
	//		glfwSwapBuffers(mp_Window);
	//	}
	//
	//	glfwPollEvents();
	//}

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

}

void Game::render(void)
{
	mp_GraphicsSystem->beginRender();

	mp_GraphicsSystem->endRender();
}
