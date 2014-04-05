
#include "Game.h"

int main( int argc, char* argv[] )
{
	Game::Instance()->start();

	Game::Destroy();

	return 0;
}