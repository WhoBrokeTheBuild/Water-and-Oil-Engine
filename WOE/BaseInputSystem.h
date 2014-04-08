#ifndef WOE_BASE_INPUT_SYSTEM_H
#define WOE_BASE_INPUT_SYSTEM_H

#include "EventDispatcher.h"

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
	{ }

	inline ~BaseInputSystem( void )
	{ }

protected:


};

#endif // WOE_BASE_INPUT_SYSTEM_H