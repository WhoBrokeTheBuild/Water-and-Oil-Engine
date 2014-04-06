#pragma once

#include <Arc/TestGroup.h>

#include "Log.h"

#include "GameTimeTests.h"

bool WOE_RunTests( void )
{
	Log::InfoFmt("Tests", "Running Unit Tests");

	TestGroup unitTests;

	TestGroup_WOE_GameTime(unitTests);

	unitTests.runTests(true);

	Log::InfoFmt("Tests", "Results, Passed %d/%d Tests", unitTests.getNumPassed(), unitTests.getNumTests());

	if (unitTests.getNumPassed() != unitTests.getNumTests())
		return false;

	return true;
}