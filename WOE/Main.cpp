
#include <Arc/MemoryTracker.h>

#include "Game.h"

using Arc::MemoryTracker;

int main( int argc, char* argv[] )
{
#if defined(_WOE_DEBUG)

	Arc::Arc_InitMemoryTracker();

#endif 

	Game::Instance()->start();

	Game::Destroy();

#if defined(_WOE_DEBUG)

	if (Arc::Arc_GetMemoryAllocationCount() > 0)
	{
		Arc::Arc_PrintMemoryAllocations();

		system("PAUSE");
	}

#endif

	return 0;
}