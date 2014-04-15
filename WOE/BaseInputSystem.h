#ifndef WOE_BASE_INPUT_SYSTEM_H
#define WOE_BASE_INPUT_SYSTEM_H

#include "EventDispatcher.h"

#include "Key.h"
#include "MouseButton.h"
#include "ScrollWheelDir.h"
#include "InputInfo.h"

class GameTime;

class BaseInputSystem
	: public EventDispatcher
{
public:

	static const EventType		EVENT_KEY_PRESSED,
								EVENT_KEY_RELEASED,
								EVENT_KEY_HELD,
								EVENT_MOUSE_BUTTON_PRESSED,
								EVENT_MOUSE_BUTTON_RELEASED,
								EVENT_MOUSE_BUTTON_HELD,
								EVENT_MOUSE_MOVED;

	inline BaseInputSystem( void )
		: m_Keys()
	{
		for (unsigned int i = 0; i < Key::WOE_NUM_KEYS; ++i)
		{
			m_Keys.add((Key)i, InputInfo());
		}
	}

	inline ~BaseInputSystem( void ) { }

	virtual void update( const GameTime* pGameTime ) = 0;

#pragma region Hooks

	void hookKeyDown( Key key );
	void hookKeyUp( Key key );
	void hookMouseButtonDown( MouseButton button );
	void hookMouseButtonUp( MouseButton button );
	void hookWheelScroll( ScrollWheelDir scrollDir );
	void hookMouseMoved( float x, float y );

#pragma endregion Hooks

protected:

	Map<Key, InputInfo>				m_Keys;

	Map<MouseButton, InputInfo>		m_MouseButtons;

	float							m_MouseX,
									m_MouseY,
									m_DeltaMouseX,
									m_DeltaMouseY;



};

#endif // WOE_BASE_INPUT_SYSTEM_H