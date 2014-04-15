#include "GLInputFunc.h"

#if defined(_WOE_OPENGL)

Key convertKeyGLFW( int glfwKey )
{
	Key key = WOE_INVALID_KEY;

	switch (glfwKey)
	{

#pragma region A - Z

	case GLFW_KEY_A:

		key = WOE_KEY_A;

		break;
	case GLFW_KEY_B:

		key = WOE_KEY_B;

		break;
	case GLFW_KEY_C:

		key = WOE_KEY_C;

		break;
	case GLFW_KEY_D:

		key = WOE_KEY_D;

		break;
	case GLFW_KEY_E:

		key = WOE_KEY_E;

		break;
	case GLFW_KEY_F:

		key = WOE_KEY_F;

		break;
	case GLFW_KEY_G:

		key = WOE_KEY_G;

		break;
	case GLFW_KEY_H:

		key = WOE_KEY_H;

		break;
	case GLFW_KEY_I:

		key = WOE_KEY_I;

		break;
	case GLFW_KEY_J:

		key = WOE_KEY_J;

		break;
	case GLFW_KEY_K:

		key = WOE_KEY_K;

		break;
	case GLFW_KEY_L:

		key = WOE_KEY_L;

		break;
	case GLFW_KEY_M:

		key = WOE_KEY_M;

		break;
	case GLFW_KEY_N:

		key = WOE_KEY_N;

		break;
	case GLFW_KEY_O:

		key = WOE_KEY_O;

		break;
	case GLFW_KEY_P:

		key = WOE_KEY_P;

		break;
	case GLFW_KEY_Q:

		key = WOE_KEY_Q;

		break;
	case GLFW_KEY_R:

		key = WOE_KEY_R;

		break;
	case GLFW_KEY_S:

		key = WOE_KEY_S;

		break;
	case GLFW_KEY_T:

		key = WOE_KEY_T;

		break;
	case GLFW_KEY_U:

		key = WOE_KEY_U;

		break;
	case GLFW_KEY_V:

		key = WOE_KEY_V;

		break;
	case GLFW_KEY_W:

		key = WOE_KEY_W;

		break;
	case GLFW_KEY_X:

		key = WOE_KEY_X;

		break;
	case GLFW_KEY_Y:

		key = WOE_KEY_Y;

		break;
	case GLFW_KEY_Z:

		key = WOE_KEY_Z;

		break;

#pragma endregion A - Z

#pragma region 0 - 9

	case GLFW_KEY_0:

		key = WOE_KEY_0;

		break;
	case GLFW_KEY_1:

		key = WOE_KEY_1;

		break;
	case GLFW_KEY_2:

		key = WOE_KEY_2;

		break;
	case GLFW_KEY_3:

		key = WOE_KEY_3;

		break;
	case GLFW_KEY_4:

		key = WOE_KEY_4;

		break;
	case GLFW_KEY_5:

		key = WOE_KEY_5;

		break;
	case GLFW_KEY_6:

		key = WOE_KEY_6;

		break;
	case GLFW_KEY_7:

		key = WOE_KEY_7;

		break;
	case GLFW_KEY_8:

		key = WOE_KEY_8;

		break;
	case GLFW_KEY_9:

		key = WOE_KEY_9;

		break;

#pragma endregion 0 - 9

#pragma region Symbols

	case GLFW_KEY_SPACE:

		key = WOE_KEY_SPACE;

		break;
	case GLFW_KEY_APOSTROPHE:

		key = WOE_KEY_APOSTROPHE;

		break;
	case GLFW_KEY_SEMICOLON:

		key = WOE_KEY_SEMICOLON;

		break;
	case GLFW_KEY_COMMA:

		key = WOE_KEY_COMMA;

		break;
	case GLFW_KEY_PERIOD:

		key = WOE_KEY_PERIOD;

		break;
	case GLFW_KEY_MINUS:

		key = WOE_KEY_DASH;

		break;
	case GLFW_KEY_SLASH:

		key = WOE_KEY_SLASH;

		break;
	case GLFW_KEY_BACKSLASH:

		key = WOE_KEY_BACKSLASH;

		break;
	case GLFW_KEY_GRAVE_ACCENT:

		key = WOE_KEY_GRAVE_ACCENT;

		break;
	case GLFW_KEY_LEFT_BRACKET:

		key = WOE_KEY_LEFT_BRACKET;

		break;
	case GLFW_KEY_RIGHT_BRACKET:

		key = WOE_KEY_RIGHT_BRACKET;

		break;

#pragma endregion Symbols

#pragma region Function Keys

	case GLFW_KEY_ESCAPE:

		key = WOE_KEY_ESCAPE;

		break;
	case GLFW_KEY_ENTER:

		key = WOE_KEY_ENTER;

		break;
	case GLFW_KEY_TAB:

		key = WOE_KEY_TAB;

		break;
	case GLFW_KEY_BACKSPACE:

		key = WOE_KEY_BACKSPACE;

		break;
	case GLFW_KEY_INSERT:

		key = WOE_KEY_INSERT;

		break;
	case GLFW_KEY_DELETE:

		key = WOE_KEY_DELETE;

		break;
	case GLFW_KEY_HOME:

		key = WOE_KEY_HOME;

		break;
	case GLFW_KEY_END:

		key = WOE_KEY_END;

		break;
	case GLFW_KEY_PAGE_UP:

		key = WOE_KEY_PAGE_UP;

		break;
	case GLFW_KEY_PAGE_DOWN:

		key = WOE_KEY_PAGE_DOWN;

		break;
	case GLFW_KEY_CAPS_LOCK:

		key = WOE_KEY_CAPS_LOCK;

		break;
	case GLFW_KEY_SCROLL_LOCK:

		key = WOE_KEY_SCROLL_LOCK;

		break;
	case GLFW_KEY_NUM_LOCK:

		key = WOE_KEY_NUM_LOCK;

		break;
	case GLFW_KEY_PRINT_SCREEN:

		key = WOE_KEY_PRINT_SCREEN;

		break;
	case GLFW_KEY_PAUSE:

		key = WOE_KEY_PAUSE;

		break;

#pragma region Arrow Keys

	case GLFW_KEY_LEFT:

		key = WOE_KEY_LEFT;

		break;
	case GLFW_KEY_UP:

		key = WOE_KEY_UP;

		break;
	case GLFW_KEY_RIGHT:

		key = WOE_KEY_RIGHT;

		break;
	case GLFW_KEY_DOWN:

		key = WOE_KEY_DOWN;

		break;

#pragma endregion Arrow Keys

#pragma region F-Keys

	case GLFW_KEY_F1:

		key = WOE_KEY_F1;

		break;
	case GLFW_KEY_F2:

		key = WOE_KEY_F2;

		break;
	case GLFW_KEY_F3:

		key = WOE_KEY_F3;

		break;
	case GLFW_KEY_F4:

		key = WOE_KEY_F4;

		break;
	case GLFW_KEY_F5:

		key = WOE_KEY_F5;

		break;
	case GLFW_KEY_F6:

		key = WOE_KEY_F6;

		break;
	case GLFW_KEY_F7:

		key = WOE_KEY_F7;

		break;
	case GLFW_KEY_F8:

		key = WOE_KEY_F8;

		break;
	case GLFW_KEY_F9:

		key = WOE_KEY_F9;

		break;
	case GLFW_KEY_F10:

		key = WOE_KEY_F10;

		break;
	case GLFW_KEY_F11:

		key = WOE_KEY_F11;

		break;
	case GLFW_KEY_F12:

		key = WOE_KEY_F12;
		
		break;

#pragma endregion F-Keys

#pragma region Key Pad

	case GLFW_KEY_KP_0:

		key = WOE_KEY_PAD_0;

		break;
	case GLFW_KEY_KP_1:

		key = WOE_KEY_PAD_1;

		break;
	case GLFW_KEY_KP_2:

		key = WOE_KEY_PAD_2;

		break;
	case GLFW_KEY_KP_3:

		key = WOE_KEY_PAD_3;

		break;
	case GLFW_KEY_KP_4:

		key = WOE_KEY_PAD_4;

		break;
	case GLFW_KEY_KP_5:

		key = WOE_KEY_PAD_5;

		break;
	case GLFW_KEY_KP_6:

		key = WOE_KEY_PAD_6;

		break;
	case GLFW_KEY_KP_7:

		key = WOE_KEY_PAD_7;

		break;
	case GLFW_KEY_KP_8:

		key = WOE_KEY_PAD_8;

		break;
	case GLFW_KEY_KP_9:

		key = WOE_KEY_PAD_9;

		break;
	case GLFW_KEY_KP_DECIMAL:

		key = WOE_KEY_PAD_DECIMAL;

		break;
	case GLFW_KEY_KP_DIVIDE:

		key = WOE_KEY_PAD_DIVIDE;

		break;
	case GLFW_KEY_KP_MULTIPLY:

		key = WOE_KEY_PAD_MULTIPLY;

		break;
	case GLFW_KEY_KP_SUBTRACT:

		key = WOE_KEY_PAD_SUBTRACT;

		break;
	case GLFW_KEY_KP_ADD:

		key = WOE_KEY_PAD_ADD;

		break;
	case GLFW_KEY_KP_ENTER:

		key = WOE_KEY_PAD_ENTER;

		break;
	case GLFW_KEY_KP_EQUAL:

		key = WOE_KEY_PAD_EQUAL;

		break;

#pragma endregion Key Pad

#pragma region Modifiers

	case GLFW_KEY_LEFT_SHIFT:

		key = WOE_KEY_LEFT_SHIFT;

		break;
	case GLFW_KEY_LEFT_CONTROL:

		key = WOE_KEY_LEFT_CTRL;

		break;
	case GLFW_KEY_LEFT_ALT:

		key = WOE_KEY_LEFT_ALT;

		break;
	case GLFW_KEY_LEFT_SUPER:

		key = WOE_KEY_LEFT_SUPER;

		break;
	case GLFW_KEY_RIGHT_SHIFT:

		key = WOE_KEY_RIGHT_SHIFT;

		break;
	case GLFW_KEY_RIGHT_CONTROL:

		key = WOE_KEY_RIGHT_CTRL;

		break;
	case GLFW_KEY_RIGHT_ALT:

		key = WOE_KEY_RIGHT_ALT;

		break;
	case GLFW_KEY_RIGHT_SUPER:

		key = WOE_KEY_RIGHT_SUPER;

		break;

#pragma endregion Modifiers

#pragma endregion Function Keys

	}

	return key;
}

MouseButton convertMouseButtonGLFW( int glfwButton )
{
	MouseButton button = WOE_INVALID_MOUSE_BUTTON;

	switch (glfwButton)
	{
	case GLFW_MOUSE_BUTTON_1:

		button = WOE_MOUSE_BUTTON_LEFT;

		break;
	case GLFW_MOUSE_BUTTON_2:

		button = WOE_MOUSE_BUTTON_RIGHT;

		break;
	case GLFW_MOUSE_BUTTON_3:

		button = WOE_MOUSE_BUTTON_MIDDLE;

		break;
	}

	return button;
}

#endif // _WOE_OPENGL