#ifndef WOE_INPUT_INFO_H
#define WOE_INPUT_INFO_H

#include "InputState.h"

struct InputInfo
{
public:

	InputInfo( void )
		: State(WOE_INVALID_INPUT_STATE),
		  PressCount(0),
		  LastPressTime(0.0),
		  HoldTime(0.0)
	{ }

	InputState		State;

	unsigned int	PressCount;

	double			LastPressTime,
					HoldTime;

};

#endif // WOE_INPUT_INFO_H