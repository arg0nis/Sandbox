#pragma once
// From glfw3.h
#define MY_KEY_SPACE              32
#define MY_KEY_APOSTROPHE         39  /* ' */
#define MY_KEY_COMMA              44  /* , */
#define MY_KEY_MINUS              45  /* - */
#define MY_KEY_PERIOD             46  /* . */
#define MY_KEY_SLASH              47  /* / */
#define MY_KEY_0                  48
#define MY_KEY_1                  49
#define MY_KEY_2                  50
#define MY_KEY_3                  51
#define MY_KEY_4                  52
#define MY_KEY_5                  53
#define MY_KEY_6                  54
#define MY_KEY_7                  55
#define MY_KEY_8                  56
#define MY_KEY_9                  57
#define MY_KEY_SEMICOLON          59  /* ; */
#define MY_KEY_EQUAL              61  /* = */
#define MY_KEY_A                  65
#define MY_KEY_B                  66
#define MY_KEY_C                  67
#define MY_KEY_D                  68
#define MY_KEY_E                  69
#define MY_KEY_F                  70
#define MY_KEY_G                  71
#define MY_KEY_H                  72
#define MY_KEY_I                  73
#define MY_KEY_J                  74
#define MY_KEY_K                  75
#define MY_KEY_L                  76
#define MY_KEY_M                  77
#define MY_KEY_N                  78
#define MY_KEY_O                  79
#define MY_KEY_P                  80
#define MY_KEY_Q                  81
#define MY_KEY_R                  82
#define MY_KEY_S                  83
#define MY_KEY_T                  84
#define MY_KEY_U                  85
#define MY_KEY_V                  86
#define MY_KEY_W                  87
#define MY_KEY_X                  88
#define MY_KEY_Y                  89
#define MY_KEY_Z                  90
#define MY_KEY_LEFT_BRACKET       91  /* [ */
#define MY_KEY_BACKSLASH          92  /* \ */
#define MY_KEY_RIGHT_BRACKET      93  /* ] */
#define MY_KEY_GRAVE_ACCENT       96  /* ` */
#define MY_KEY_WORLD_1            161 /* non-US #1 */
#define MY_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define MY_KEY_ESCAPE             256
#define MY_KEY_ENTER              257
#define MY_KEY_TAB                258
#define MY_KEY_BACKSPACE          259
#define MY_KEY_INSERT             260
#define MY_KEY_DELETE             261
#define MY_KEY_RIGHT              262
#define MY_KEY_LEFT               263
#define MY_KEY_DOWN               264
#define MY_KEY_UP                 265
#define MY_KEY_PAGE_UP            266
#define MY_KEY_PAGE_DOWN          267
#define MY_KEY_HOME               268
#define MY_KEY_END                269
#define MY_KEY_CAPS_LOCK          280
#define MY_KEY_SCROLL_LOCK        281
#define MY_KEY_NUM_LOCK           282
#define MY_KEY_PRINT_SCREEN       283
#define MY_KEY_PAUSE              284
#define MY_KEY_F1                 290
#define MY_KEY_F2                 291
#define MY_KEY_F3                 292
#define MY_KEY_F4                 293
#define MY_KEY_F5                 294
#define MY_KEY_F6                 295
#define MY_KEY_F7                 296
#define MY_KEY_F8                 297
#define MY_KEY_F9                 298
#define MY_KEY_F10                299
#define MY_KEY_F11                300
#define MY_KEY_F12                301
#define MY_KEY_F13                302
#define MY_KEY_F14                303
#define MY_KEY_F15                304
#define MY_KEY_F16                305
#define MY_KEY_F17                306
#define MY_KEY_F18                307
#define MY_KEY_F19                308
#define MY_KEY_F20                309
#define MY_KEY_F21                310
#define MY_KEY_F22                311
#define MY_KEY_F23                312
#define MY_KEY_F24                313
#define MY_KEY_F25                314
#define MY_KEY_KP_0               320
#define MY_KEY_KP_1               321
#define MY_KEY_KP_2               322
#define MY_KEY_KP_3               323
#define MY_KEY_KP_4               324
#define MY_KEY_KP_5               325
#define MY_KEY_KP_6               326
#define MY_KEY_KP_7               327
#define MY_KEY_KP_8               328
#define MY_KEY_KP_9               329
#define MY_KEY_KP_DECIMAL         330
#define MY_KEY_KP_DIVIDE          331
#define MY_KEY_KP_MULTIPLY        332
#define MY_KEY_KP_SUBTRACT        333
#define MY_KEY_KP_ADD             334
#define MY_KEY_KP_ENTER           335
#define MY_KEY_KP_EQUAL           336
#define MY_KEY_LEFT_SHIFT         16//340
#define MY_KEY_LEFT_CONTROL       17//341
#define MY_KEY_LEFT_ALT           342
#define MY_KEY_LEFT_SUPER         343
#define MY_KEY_RIGHT_SHIFT        344
#define MY_KEY_RIGHT_CONTROL      345
#define MY_KEY_RIGHT_ALT          346
#define MY_KEY_RIGHT_SUPER        347
#define MY_KEY_MENU               348
#define MY_KEY_LAST               MY_KEY_MENU

#define MY_KEY_LEFT_SHIFT_GLFW	340					// special case
#define MY_KEY_LEFT_CONTROL_GLFW	341					// special case

#define MY_MOUSE_LEFT				350
#define MY_MOUSE_RIGHT			351

#define MY_KEY_WIN_ENTER        13
#define MY_KEY_WIN_SHIFT         16
#define MY_KEY_WIN_CONTROL       17
#define MY_KEY_WIN_ALT		   18
#define MY_KEY_WIN_TAB           9
#define MY_KEY_WIN_CAPSLOCK      20
#define MY_KEY_WIN_ESCAPE			27

/*#define MY_CONTROLLER_BUTTON_0	352
#define MY_CONTROLLER_BUTTON_1    353
#define MY_CONTROLLER_BUTTON_2    354
#define MY_CONTROLLER_BUTTON_3    355
#define MY_CONTROLLER_BUTTON_4    356
#define MY_CONTROLLER_BUTTON_5    357
#define MY_CONTROLLER_BUTTON_6    358
#define MY_CONTROLLER_BUTTON_7    359
#define MY_CONTROLLER_BUTTON_8    360
#define MY_CONTROLLER_BUTTON_9    361
#define MY_CONTROLLER_BUTTON_10	362
#define MY_CONTROLLER_BUTTON_11    363
#define MY_CONTROLLER_BUTTON_12    364
#define MY_CONTROLLER_BUTTON_13    365
#define MY_CONTROLLER_BUTTON_14    366
#define MY_CONTROLLER_BUTTON_15    367
#define MY_CONTROLLER_BUTTON_16    368
#define MY_CONTROLLER_BUTTON_17    369
#define MY_CONTROLLER_BUTTON_18    370
#define MY_CONTROLLER_BUTTON_19    371*/

#define MY_PS_4_CONTROLLER_CROSS			1	//0
#define MY_PS_4_CONTROLLER_CIRCLE			2	//1
#define MY_PS_4_CONTROLLER_SQUARE			0	//2
#define MY_PS_4_CONTROLLER_TRIANGLE		3
#define MY_PS_4_CONTROLLER_L1			    4
#define MY_PS_4_CONTROLLER_L2			    6
#define MY_PS_4_CONTROLLER_L3			    10	//9
#define MY_PS_4_CONTROLLER_R1			    5
#define MY_PS_4_CONTROLLER_R2			    7
#define MY_PS_4_CONTROLLER_R3			    11	//10
#define MY_PS_4_CONTROLLER_SHARE			6
#define MY_PS_4_CONTROLLER_OPTIONS		9	//7
#define MY_PS_4_CONTROLLER_PS_BUTTON	    12	//8
#define MY_PS_4_CONTROLLER_DPAD_UP		14	//11
#define MY_PS_4_CONTROLLER_DPAD_RIGHT		15	//12
#define MY_PS_4_CONTROLLER_DPAD_DOWN		16	//13
#define MY_PS_4_CONTROLLER_DPAD_LEFT		17	//14
#define MY_PS_4_CONTROLLER_TRIGGER_L		18			// you manually chose this button code so u can store it in the same buttons vector
#define MY_PS_4_CONTROLLER_TRIGGER_R		19			// you manually chose this button code so u can store it in the same buttons vector



#define MY_XBOX_CONTROLLER_A				0
#define MY_XBOX_CONTROLLER_B				1
#define MY_XBOX_CONTROLLER_X				2
#define MY_XBOX_CONTROLLER_Y				3
#define MY_XBOX_CONTROLLER_L1			    4
#define MY_XBOX_CONTROLLER_R1			    5
#define MY_XBOX_CONTROLLER_WIERD_1		6
#define MY_XBOX_CONTROLLER_WIERD_2		7
#define MY_XBOX_CONTROLLER_L3			    8
#define MY_XBOX_CONTROLLER_R3			    9
#define MY_XBOX_CONTROLLER_DPAD_UP		10
#define MY_XBOX_CONTROLLER_DPAD_RIGHT		11
#define MY_XBOX_CONTROLLER_DPAD_DOWN		12
#define MY_XBOX_CONTROLLER_DPAD_LEFT		13
#define MY_XBOX_CONTROLLER_TRIGGER_L		14			// you manually chose this button code so u can store it in the same buttons vector
#define MY_XBOX_CONTROLLER_TRIGGER_R		15			// you manually chose this button code so u can store it in the same buttons vector

#define MY_KEY_NUMPAD_0               320
#define MY_KEY_NUMPAD_1               321
#define MY_KEY_NUMPAD_2               322
#define MY_KEY_NUMPAD_3               323
#define MY_KEY_NUMPAD_4               324
#define MY_KEY_NUMPAD_5               325
#define MY_KEY_NUMPAD_6               326
#define MY_KEY_NUMPAD_7               327
#define MY_KEY_NUMPAD_8               328
#define MY_KEY_NUMPAD_9               329
#define MY_KEY_NUMPAD_DECIMAL         330
#define MY_KEY_NUMPAD_DIVIDE          331
#define MY_KEY_NUMPAD_MULTIPLY        332
#define MY_KEY_NUMPAD_SUBTRACT        333
#define MY_KEY_NUMPAD_ADD             334
#define MY_KEY_NUMPAD_ENTER           335
#define MY_KEY_NUMPAD_EQUAL           336
