#pragma once
#ifndef _LM_INPUTS
#define _LM_INPUTS
namespace LocoMotor {
	//These key codes act as intermediaries between the InputManager and SDL,
	//this way we can avoid including SDL in the InputManager header
	///@brief Key codes for keyboard input
	///@note scan codes are generally symbol dependent, so they usually change depending on keyboard layout
	enum LMKeyboard {
		LMK_UNKNOWN = 0,

		LMK_RETURN = '\r',
		LMK_ESCAPE = '\x1B',
		LMK_BACKSPACE = '\b',
		LMK_TAB = '\t',
		LMK_SPACE = ' ',
		LMK_EXCLAIM = '!',
		LMK_QUOTEDBL = '"',
		LMK_HASH = '#',
		LMK_PERCENT = '%',
		LMK_DOLLAR = '$',
		LMK_AMPERSAND = '&',
		LMK_QUOTE = '\'',
		LMK_LEFTPAREN = '(',
		LMK_RIGHTPAREN = ')',
		LMK_ASTERISK = '*',
		LMK_PLUS = '+',
		LMK_COMMA = ',',
		LMK_MINUS = '-',
		LMK_PERIOD = '.',
		LMK_SLASH = '/',
		LMK_0 = '0',
		LMK_1 = '1',
		LMK_2 = '2',
		LMK_3 = '3',
		LMK_4 = '4',
		LMK_5 = '5',
		LMK_6 = '6',
		LMK_7 = '7',
		LMK_8 = '8',
		LMK_9 = '9',
		LMK_COLON = ':',
		LMK_SEMICOLON = ';',
		LMK_LESS = '<',
		LMK_EQUALS = '=',
		LMK_GREATER = '>',
		LMK_QUESTION = '?',
		LMK_AT = '@',

		LMK_LEFTBRACKET = '[',
		LMK_BACKSLASH = '\\',
		LMK_RIGHTBRACKET = ']',
		LMK_CARET = '^',
		LMK_UNDERSCORE = '_',
		LMK_BACKQUOTE = '`',
		LMK_a = 'a',
		LMK_b = 'b',
		LMK_c = 'c',
		LMK_d = 'd',
		LMK_e = 'e',
		LMK_f = 'f',
		LMK_g = 'g',
		LMK_h = 'h',
		LMK_i = 'i',
		LMK_j = 'j',
		LMK_k = 'k',
		LMK_l = 'l',
		LMK_m = 'm',
		LMK_n = 'n',
		LMK_o = 'o',
		LMK_p = 'p',
		LMK_q = 'q',
		LMK_r = 'r',
		LMK_s = 's',
		LMK_t = 't',
		LMK_u = 'u',
		LMK_v = 'v',
		LMK_w = 'w',
		LMK_x = 'x',
		LMK_y = 'y',
		LMK_z = 'z',

		LMK_CAPSLOCK = 1073741881,

		LMK_F1 = 1073741882,
		LMK_F2 = 1073741883,
		LMK_F3 = 1073741884,
		LMK_F4 = 1073741885,
		LMK_F5 = 1073741886,
		LMK_F6 = 1073741887,
		LMK_F7 = 1073741888,
		LMK_F8 = 1073741889,
		LMK_F9 = 1073741890,
		LMK_F10 = 1073741891,
		LMK_F11 = 1073741892,
		LMK_F12 = 1073741893,

		LMK_PRINTSCREEN = 1073741894,
		LMK_SCROLLLOCK = 1073741895,
		LMK_PAUSE = 1073741896,
		LMK_INSERT = 1073741897,
		LMK_HOME = 1073741898,
		LMK_PAGEUP = 1073741899,
		LMK_DELETE = '\x7F',
		LMK_END = 1073741901,
		LMK_PAGEDOWN = 1073741902,
		LMK_RIGHT = 1073741903,
		LMK_LEFT = 1073741904,
		LMK_DOWN = 1073741905,
		LMK_UP = 1073741906,

		LMK_NUMLOCKCLEAR = 1073741907,
		LMK_KP_DIVIDE = 1073741908,
		LMK_KP_MULTIPLY = 1073741909,
		LMK_KP_MINUS = 1073741910,
		LMK_KP_PLUS = 1073741911,
		LMK_KP_ENTER = 1073741912,
		LMK_KP_1 = 1073741913,
		LMK_KP_2 = 1073741914,
		LMK_KP_3 = 1073741915,
		LMK_KP_4 = 1073741916,
		LMK_KP_5 = 1073741917,
		LMK_KP_6 = 1073741918,
		LMK_KP_7 = 1073741919,
		LMK_KP_8 = 1073741920,
		LMK_KP_9 = 1073741921,
		LMK_KP_0 = 1073741922,
		LMK_KP_PERIOD = 1073741923,


		LMK_KP_TAB = 1073742010,
		LMK_KP_BACKSPACE = 1073742011,

		LMK_KP_COLON = 1073742027,
		LMK_KP_HASH = 1073742028,
		LMK_KP_SPACE = 1073742029,


		LMK_LCTRL = 1073742048,
		LMK_LSHIFT = 1073742049,
		LMK_LALT = 1073742050,
		LMK_LGUI = 1073742051,
		LMK_RCTRL = 1073742052,
		LMK_RSHIFT = 1073742053,
		LMK_RALT = 1073742054,
		LMK_RGUI = 1073742055,

		LMK_MODE = 1073742081,
	};

	//These scan codes act as intermediaries between the InputManager and SDL,
	//this way we can avoid including SDL in the InputManager header.
	///@brief Scan Codes for keyboard input
	///@note scan codes are generally dependent on position rather than symbol, so they don't tend to change between keyboard layouts
	enum LMScanCode {
		LMKS_UNKNOWN = 0,

		LMKS_A = 4,
		LMKS_B = 5,
		LMKS_C = 6,
		LMKS_D = 7,
		LMKS_E = 8,
		LMKS_F = 9,
		LMKS_G = 10,
		LMKS_H = 11,
		LMKS_I = 12,
		LMKS_J = 13,
		LMKS_K = 14,
		LMKS_L = 15,
		LMKS_M = 16,
		LMKS_N = 17,
		LMKS_O = 18,
		LMKS_P = 19,
		LMKS_Q = 20,
		LMKS_R = 21,
		LMKS_S = 22,
		LMKS_T = 23,
		LMKS_U = 24,
		LMKS_V = 25,
		LMKS_W = 26,
		LMKS_X = 27,
		LMKS_Y = 28,
		LMKS_Z = 29,

		LMKS_1 = 30,
		LMKS_2 = 31,
		LMKS_3 = 32,
		LMKS_4 = 33,
		LMKS_5 = 34,
		LMKS_6 = 35,
		LMKS_7 = 36,
		LMKS_8 = 37,
		LMKS_9 = 38,
		LMKS_0 = 39,

		LMKS_RETURN = 40,
		LMKS_ESCAPE = 41,
		LMKS_BACKSPACE = 42,
		LMKS_TAB = 43,
		LMKS_SPACE = 44,

		LMKS_MINUS = 45,
		LMKS_EQUALS = 46,
		LMKS_LEFTBRACKET = 47,
		LMKS_RIGHTBRACKET = 48,
		LMKS_BACKSLASH = 49,

		LMKS_SEMICOLON = 51,
		LMKS_APOSTROPHE = 52,
		LMKS_GRAVE = 53,
		LMKS_COMMA = 54,
		LMKS_PERIOD = 55,
		LMKS_SLASH = 56,

		LMKS_CAPSLOCK = 57,

		LMKS_F1 = 58,
		LMKS_F2 = 59,
		LMKS_F3 = 60,
		LMKS_F4 = 61,
		LMKS_F5 = 62,
		LMKS_F6 = 63,
		LMKS_F7 = 64,
		LMKS_F8 = 65,
		LMKS_F9 = 66,
		LMKS_F10 = 67,
		LMKS_F11 = 68,
		LMKS_F12 = 69,

		LMKS_PRINTSCREEN = 70,
		LMKS_SCROLLLOCK = 71,
		LMKS_PAUSE = 72,
		LMKS_INSERT = 73,
		LMKS_HOME = 74,
		LMKS_PAGEUP = 75,
		LMKS_DELETE = 76,
		LMKS_END = 77,
		LMKS_PAGEDOWN = 78,
		LMKS_RIGHT = 79,
		LMKS_LEFT = 80,
		LMKS_DOWN = 81,
		LMKS_UP = 82,

		LMKS_NUMLOCKCLEAR = 83,
		LMKS_KP_DIVIDE = 84,
		LMKS_KP_MULTIPLY = 85,
		LMKS_KP_MINUS = 86,
		LMKS_KP_PLUS = 87,
		LMKS_KP_ENTER = 88,
		LMKS_KP_1 = 89,
		LMKS_KP_2 = 90,
		LMKS_KP_3 = 91,
		LMKS_KP_4 = 92,
		LMKS_KP_5 = 93,
		LMKS_KP_6 = 94,
		LMKS_KP_7 = 95,
		LMKS_KP_8 = 96,
		LMKS_KP_9 = 97,
		LMKS_KP_0 = 98,
		LMKS_KP_PERIOD = 99,

		LMKS_LCTRL = 224,
		LMKS_LSHIFT = 225,
		LMKS_LALT = 226,
		LMKS_LGUI = 227,
		LMKS_RCTRL = 228,
		LMKS_RSHIFT = 229,
		LMKS_RALT = 230,
		LMKS_RGUI = 231,

		LMKS_MODE = 257,
	};

	//Enum to define controller button codes
	///@brief Controller button codes
	enum LMControllerButtons {
		LMC_A = 0,
		LMC_B = 1,
		LMC_X = 2,
		LMC_Y = 3,
		LMC_BACK = 4,
		LMC_GUIDE = 5,
		LMC_START = 6,
		LMC_LEFTSTICK = 7,
		LMC_RIGHTSTICK = 8,
		LMC_LEFTSHOULDER = 9,
		LMC_RIGHTSHOULDER = 10,
		LMC_DPAD_UP = 11,
		LMC_DPAD_DOWN = 12,
		LMC_DPAD_LEFT = 13,
		LMC_DPAD_RIGHT = 14,
		LMC_MISC1 = 15,
		LMC_PADDLE1 = 16,
		LMC_PADDLE2 = 17,
		LMC_PADDLE3 = 18,
		LMC_PADDLE4 = 19,
		LMC_TOUCHPAD = 20,
		LMC_MAX = 21,

	};
}


#endif