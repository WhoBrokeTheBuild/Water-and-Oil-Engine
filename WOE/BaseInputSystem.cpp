#include "BaseInputSystem.h"

#include "Game.h"
#include "GameTime.h"

const EventType BaseInputSystem::EVENT_KEY_PRESSED				= "inputSystem.keyPressed";
const EventType BaseInputSystem::EVENT_KEY_RELEASED				= "inputSystem.keyPressed";
const EventType BaseInputSystem::EVENT_KEY_HELD					= "inputSystem.keyPressed";
const EventType BaseInputSystem::EVENT_MOUSE_BUTTON_PRESSED		= "inputSystem.keyPressed";
const EventType BaseInputSystem::EVENT_MOUSE_BUTTON_RELEASED	= "inputSystem.keyPressed";
const EventType BaseInputSystem::EVENT_MOUSE_BUTTON_HELD		= "inputSystem.keyPressed";
const EventType BaseInputSystem::EVENT_MOUSE_MOVED				= "inputSystem.keyPressed";

void BaseInputSystem::hookKeyDown( Key key )
{
	m_Keys[key].PressCount++;
	m_Keys[key].State = InputState::WOE_INPUT_STATE_DOWN;
	m_Keys[key].LastPressTime = Game::Instance()->getGameTime()->getTotalElapsedMS();
}

void BaseInputSystem::hookKeyUp( Key key )
{
	m_Keys[key].State = InputState::WOE_INPUT_STATE_UP;
	m_Keys[key].HoldTime = 0.0f;
}

void BaseInputSystem::hookMouseButtonDown( MouseButton button )
{

}

void BaseInputSystem::hookMouseButtonUp( MouseButton button )
{

}

void BaseInputSystem::hookWheelScroll( ScrollWheelDir scrollDir )
{

}

void BaseInputSystem::hookMouseMoved( float x, float y )
{
	m_DeltaMouseX = x - m_MouseX;
	m_DeltaMouseY = y - m_MouseY;

	m_MouseX = x;
	m_MouseY = y;
}
