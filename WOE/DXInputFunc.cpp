#include "DXInputFunc.h"

#if defined(_WOE_DIRECTX)

#include "Log.h"

Key convertDXKey( WPARAM wParam )
{
	Key key = WOE_INVALID_KEY;

	switch (wParam)
	{

#pragma region A - Z

	case 'A':

		key = WOE_KEY_A;

		break;
	case 'B':

		key = WOE_KEY_B;

		break;
	case 'C':

		key = WOE_KEY_C;

		break;
	case 'D':

		key = WOE_KEY_D;

		break;
	case 'E':

		key = WOE_KEY_E;

		break;
	case 'F':

		key = WOE_KEY_F;

		break;
	case 'G':

		key = WOE_KEY_G;

		break;
	case 'H':

		key = WOE_KEY_H;

		break;
	case 'I':

		key = WOE_KEY_I;

		break;
	case 'J':

		key = WOE_KEY_J;

		break;
	case 'K':

		key = WOE_KEY_K;

		break;
	case 'L':

		key = WOE_KEY_L;

		break;
	case 'M':

		key = WOE_KEY_M;

		break;
	case 'N':

		key = WOE_KEY_N;

		break;
	case 'O':

		key = WOE_KEY_O;

		break;
	case 'P':

		key = WOE_KEY_P;

		break;
	case 'Q':

		key = WOE_KEY_Q;

		break;
	case 'R':

		key = WOE_KEY_R;

		break;
	case 'S':

		key = WOE_KEY_S;

		break;
	case 'T':

		key = WOE_KEY_T;

		break;
	case 'U':

		key = WOE_KEY_U;

		break;
	case 'V':

		key = WOE_KEY_V;

		break;
	case 'W':

		key = WOE_KEY_W;

		break;
	case 'X':

		key = WOE_KEY_X;

		break;
	case 'Y':

		key = WOE_KEY_Y;

		break;
	case 'Z':

		key = WOE_KEY_Z;

		break;

#pragma endregion A - Z

#pragma region 0 - 9

	case '0':

		key = WOE_KEY_0;

		break;
	case '1':

		key = WOE_KEY_1;

		break;
	case '2':

		key = WOE_KEY_2;

		break;
	case '3':

		key = WOE_KEY_3;

		break;
	case '4':

		key = WOE_KEY_4;

		break;
	case '5':

		key = WOE_KEY_5;

		break;
	case '6':

		key = WOE_KEY_6;

		break;
	case '7':

		key = WOE_KEY_7;

		break;
	case '8':

		key = WOE_KEY_8;

		break;
	case '9':

		key = WOE_KEY_9;

		break;

#pragma endregion 0 - 9

#pragma region Symbols

	case VK_SPACE:

		key = WOE_KEY_SPACE;

		break;
	case VK_OEM_7:

		key = WOE_KEY_APOSTROPHE;

		break;
	case VK_OEM_1:

		key = WOE_KEY_SEMICOLON;

		break;
	case VK_OEM_COMMA:

		key = WOE_KEY_COMMA;

		break;
	case VK_OEM_PERIOD:

		key = WOE_KEY_PERIOD;

		break;
	case VK_OEM_MINUS:

		key = WOE_KEY_DASH;

		break;
	case VK_OEM_2:

		key = WOE_KEY_SLASH;

		break;
	case VK_OEM_5:

		key = WOE_KEY_BACKSLASH;

		break;
	case VK_OEM_3:

		key = WOE_KEY_GRAVE_ACCENT;

		break;
	case VK_OEM_4:

		key = WOE_KEY_LEFT_BRACKET;

		break;
	case VK_OEM_6:

		key = WOE_KEY_RIGHT_BRACKET;

		break;

#pragma endregion Symbols

#pragma region Function Keys

	case VK_ESCAPE:

		key = WOE_KEY_ESCAPE;

		break;
	case '\r':

		key = WOE_KEY_ENTER;

		break;
	case VK_TAB:

		key = WOE_KEY_TAB;

		break;
	case VK_BACK:

		key = WOE_KEY_BACKSPACE;

		break;
	case VK_INSERT:

		key = WOE_KEY_INSERT;

		break;
	case VK_DELETE:

		key = WOE_KEY_DELETE;

		break;
	case VK_HOME:

		key = WOE_KEY_HOME;

		break;
	case VK_END:

		key = WOE_KEY_END;

		break;
	case VK_PRIOR:

		key = WOE_KEY_PAGE_UP;

		break;
	case VK_NEXT:

		key = WOE_KEY_PAGE_DOWN;

		break;
	case VK_CAPITAL:

		key = WOE_KEY_CAPS_LOCK;

		break;
	case VK_SCROLL:

		key = WOE_KEY_SCROLL_LOCK;

		break;
	case VK_NUMLOCK:

		key = WOE_KEY_NUM_LOCK;

		break;
	case VK_SNAPSHOT:

		key = WOE_KEY_PRINT_SCREEN;

		break;
	case VK_PAUSE:

		key = WOE_KEY_PAUSE;

		break;

#pragma region Arrow Keys

	case VK_LEFT:

		key = WOE_KEY_LEFT;

		break;
	case VK_UP:

		key = WOE_KEY_UP;

		break;
	case VK_RIGHT:

		key = WOE_KEY_RIGHT;

		break;
	case VK_DOWN:

		key = WOE_KEY_DOWN;

		break;

#pragma endregion Arrow Keys

#pragma region F-Keys

	case VK_F1:

		key = WOE_KEY_F1;

		break;
	case VK_F2:

		key = WOE_KEY_F2;

		break;
	case VK_F3:

		key = WOE_KEY_F3;

		break;
	case VK_F4:

		key = WOE_KEY_F4;

		break;
	case VK_F5:

		key = WOE_KEY_F5;

		break;
	case VK_F6:

		key = WOE_KEY_F6;

		break;
	case VK_F7:

		key = WOE_KEY_F7;

		break;
	case VK_F8:

		key = WOE_KEY_F8;

		break;
	case VK_F9:

		key = WOE_KEY_F9;

		break;
	case VK_F10:

		key = WOE_KEY_F10;

		break;
	case VK_F11:

		key = WOE_KEY_F11;

		break;
	case VK_F12:

		key = WOE_KEY_F12;

		break;

#pragma endregion F-Keys

#pragma region Key Pad

	case VK_NUMPAD0:

		key = WOE_KEY_PAD_0;

		break;
	case VK_NUMPAD1:

		key = WOE_KEY_PAD_1;

		break;
	case VK_NUMPAD2:

		key = WOE_KEY_PAD_2;

		break;
	case VK_NUMPAD3:

		key = WOE_KEY_PAD_3;

		break;
	case VK_NUMPAD4:

		key = WOE_KEY_PAD_4;

		break;
	case VK_NUMPAD5:

		key = WOE_KEY_PAD_5;

		break;
	case VK_NUMPAD6:

		key = WOE_KEY_PAD_6;

		break;
	case VK_NUMPAD7:

		key = WOE_KEY_PAD_7;

		break;
	case VK_NUMPAD8:

		key = WOE_KEY_PAD_8;

		break;
	case VK_NUMPAD9:

		key = WOE_KEY_PAD_9;

		break;
	case VK_DECIMAL:

		key = WOE_KEY_PAD_DECIMAL;

		break;
	case VK_DIVIDE:

		key = WOE_KEY_PAD_DIVIDE;

		break;
	case VK_MULTIPLY:

		key = WOE_KEY_PAD_MULTIPLY;

		break;
	case VK_SUBTRACT:

		key = WOE_KEY_PAD_SUBTRACT;

		break;
	case VK_ADD:

		key = WOE_KEY_PAD_ADD;

		break;
	//case :
	//
	//	key = WOE_KEY_PAD_ENTER;
	//
	//	break;
	//case :
	//
	//	key = WOE_KEY_PAD_EQUAL;
	//
	//	break;

#pragma endregion Key Pad

#pragma region Modifiers

	case VK_LSHIFT:

		key = WOE_KEY_LEFT_SHIFT;

		break;
	case VK_LCONTROL:

		key = WOE_KEY_LEFT_CTRL;

		break;
	case VK_LMENU:

		key = WOE_KEY_LEFT_ALT;

		break;
	case VK_LWIN:

		key = WOE_KEY_LEFT_SUPER;

		break;
	case VK_RSHIFT:

		key = WOE_KEY_RIGHT_SHIFT;

		break;
	case VK_RCONTROL:

		key = WOE_KEY_RIGHT_CTRL;

		break;
	case VK_RMENU:

		key = WOE_KEY_RIGHT_ALT;

		break;
	case VK_RWIN:

		key = WOE_KEY_RIGHT_SUPER;

		break;

#pragma endregion Modifiers

#pragma endregion Function Keys

	}

	return key;
}

#endif // _WOE_DIRECTX