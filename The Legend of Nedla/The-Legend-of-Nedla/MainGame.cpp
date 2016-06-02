#include "MainGame.h"

MainGame::MainGame()
{
	_window = nullptr; // nullptr?
	_screenWidth = 1024;
	_screenHeight = 768;
}


MainGame::~MainGame()
{
}



void MainGame::run()
{
	initSystems();
}

void MainGame::initSystems()
{
	//	Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("The Legend of Nedla", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL); // If the window creation fails it returns false
}

SDL_Window* MainGame::getWindow()
{
	return this->_window;
}