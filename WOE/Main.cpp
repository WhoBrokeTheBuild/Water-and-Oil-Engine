
#include <Arc/MemoryTracker.h>

#include "Defines.h"
#include "Game.h"
#include "Tests.h"

using Arc::MemoryTracker;

int main( int argc, char* argv[] )
{
#if defined(_WOE_DEBUG)

	Arc::Arc_InitMemoryTracker();

#endif

	Log::AddInfoOutput("stdout");
	Log::AddErrorOutput("stderr");

	Log::AddInfoOutput("info.log", false);
	Log::AddErrorOutput("error.log", false);

#if defined(WOE_UNIT_TESTS)

	WOE_RunTests();

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