#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();
	void initSystems();
	SDL_Window* getWindow();

private:
	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
};