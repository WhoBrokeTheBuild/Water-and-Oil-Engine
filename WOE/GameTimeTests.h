#pragma once

#include <Arc/TestGroup.h>
#include <Arc/TestResult.h>

#include "GameTime.h"

using Arc::TestGroup;
using Arc::TestResult;

TestResult Test_WOE_GameTime_ElapsedMS( void )
{
	GameTime gameTime;
	gameTime.setTargetFPS(60.0);

	double total = 0.0;
	double step = 1000.0 / 60.0;

	for (int i = 0; i < 10; ++i)
	{
		gameTime.updateTime(step);
		total += step;
	}

	if (gameTime.getElapsedMS() != total)
		return TestGroup::Failure("Invalid Result");

	return TestGroup::Success();
}

TestResult Test_WOE_GameTime_DeltaMS( void )
{
	GameTime gameTime;
	gameTime.setTargetFPS(60.0);

	gameTime.updateTime(1000.0 / 60.0);

	if (gameTime.getDeltaMS() != (1000.0 / 60.0))
		return TestGroup::Failure("Invalid Result");

	return TestGroup::Success();
}

TestResult Test_WOE_GameTime_DeltaMod( void )
{
	GameTime gameTime;
	gameTime.setTargetFPS(60.0);

	gameTime.updateTime(1000.0 / 60.0);

	if (gameTime.getDeltaMod() != 1.0)
		return TestGroup::Failure("Invalid Result");

	gameTime.updateTime(1000.0 / 120.0);

	if (gameTime.getDeltaMod() != 2.0)
		return TestGroup::Failure("Invalid Result");

	return TestGroup::Success();
}

TestResult Test_WOE_GameTime_TargetFPS( void )
{
	GameTime gameTime;
	gameTime.setTargetFPS(60.0);

	if (gameTime.getTargetFPS() != 60.0)
		return TestGroup::Failure("Invalid Result");

	return TestGroup::Success();
}

TestResult Test_WOE_GameTime_CurrentFPS( void )
{
	GameTime gameTime;
	gameTime.setTargetFPS(60.0);

	gameTime.updateTime(1000.0 / 60.0);

	if (gameTime.getCurrentFPS() != 60.0)
		return TestGroup::Failure("Invalid Result");

	gameTime.updateTime(1000.0 / 120.0);

	if (gameTime.getCurrentFPS() != 30.0)
		return TestGroup::Failure("Invalid Result");

	return TestGroup::Success();
}

TestResult Test_WOE_GameTime_CurrentFPSPercent( void )
{
	GameTime gameTime;
	gameTime.setTargetFPS(60.0);

	gameTime.updateTime(1000.0 / 60.0);

	if (gameTime.getCurrentFPSPercent() != 1.0)
		return TestGroup::Failure("Invalid Result");

	gameTime.updateTime(1000.0 / 120.0);

	if (gameTime.getCurrentFPSPercent() != 0.5)
		return TestGroup::Failure("Invalid Result");

	return TestGroup::Success();
}

TestResult Test_WOE_GameTime_FrameDelayMS( void )
{
	GameTime gameTime;
	gameTime.setTargetFPS(60.0);

	if (gameTime.getFrameDelayMS() != (1000.0 / 60.0))
		return TestGroup::Failure("Invalid Result");

	return TestGroup::Success();
}

void TestGroup_WOE_GameTime( TestGroup& group )
{
	group.addTest("Test_WOE_GameTime_ElapsedMS",			Test_WOE_GameTime_ElapsedMS);
	group.addTest("Test_WOE_GameTime_DeltaMS",				Test_WOE_GameTime_DeltaMS);
	group.addTest("Test_WOE_GameTime_DeltaMod",				Test_WOE_GameTime_DeltaMod);
	group.addTest("Test_WOE_GameTime_TargetFPS",			Test_WOE_GameTime_TargetFPS);
	group.addTest("Test_WOE_GameTime_CurrentFPS",			Test_WOE_GameTime_CurrentFPS);
	group.addTest("Test_WOE_GameTime_CurrentFPSPercent",	Test_WOE_GameTime_CurrentFPSPercent);
	group.addTest("Test_WOE_GameTime_FrameDelayMS",			Test_WOE_GameTime_FrameDelayMS);
}