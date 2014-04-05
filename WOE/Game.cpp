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

}

Game::~Game( void )
{

}

void Game::start( void )
{
	system("PAUSE");
}
