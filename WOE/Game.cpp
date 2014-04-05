#include "Game.h"

Game* Game::s_Instance = nullptr;

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
	while (m_Running)
	{
		mp_GraphicsSystem->beginRender();
		mp_GraphicsSystem->endRender();
	}
}
