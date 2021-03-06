#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#ifdef __APPLE__
	#include <SDL2/SDL.h>
#else
	#include "SDL.h"
#endif

#include <iostream>
#include <vector>
#include <string>

#include "Vec2.hpp"

#define LEFT_ARROW_KEY 		SDLK_LEFT
#define RIGHT_ARROW_KEY 	SDLK_RIGHT
#define UP_ARROW_KEY 		SDLK_UP
#define DOWN_ARROW_KEY 		SDLK_DOWN
#define ESCAPE_KEY 			SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON 	SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON 	SDL_BUTTON_RIGHT
#define SPACE_BAR 			SDLK_SPACE
#define BACKSPACE			SDLK_BACKSPACE
#define NUMKEY_1			SDLK_1
#define NUMKEY_2			SDLK_2
#define NUMKEY_3			SDLK_3
#define NUMKEY_4			SDLK_4
#define NUMKEY_5			SDLK_5
#define NUMKEY_6			SDLK_6
#define NUMKEY_7			SDLK_7
#define NUMKEY_8			SDLK_8

#define GAMEPAD_A 			0
#define GAMEPAD_B 			1
#define GAMEPAD_X 			2
#define GAMEPAD_Y 			3
#define GAMEPAD_LB 			4
#define GAMEPAD_RB 			5
#define GAMEPAD_ARROW_UP 	11
#define GAMEPAD_ARROW_DOWN 	12
#define GAMEPAD_ARROW_LEFT 	13
#define GAMEPAD_ARROW_RIGHT 14

class InputHandler
{
public:
	static InputHandler& getInstance();

	void update();

	bool keyPress(int key);
	bool keyRelease(int key);
	bool isKeyDown(int key);

	bool textInput();
	std::string getText();

	bool mousePress(int button);
	bool mouseRelease(int button);
	bool isMouseDown(int button);

	bool mouseWheelScroll();
	int mouseWheelAmount();

	int getMouseX();
	int getMouseY();
	Vec2 getMouse();

	bool gamePadPress(int button);
	bool gamePadRelease(int button);
	bool isGamePadDown(int button);

	bool getScreenResized();
	bool quitRequested();

private:
	InputHandler();
	~InputHandler(){}

	bool mouseState[6];
	int mouseUpdate[6];

	int mouseWheel;

	int mouseX;
	int mouseY;

	bool keyState[416];
	int keyUpdate[416];

	bool gamePadState[15];
	int gamePadUpdate[15];

	bool quit;
	int updateCounter;

	const int JOYSTICK_DEAD_ZONE = 10000;

	bool screenResized;

	std::string inputText;
};

#endif
