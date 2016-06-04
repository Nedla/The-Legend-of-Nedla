#include <iostream>
#include <string>

#include "MainGame.h"
#include "Sprite.h"

//Error checker
void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	std::cin.get();
	SDL_Quit();
	exit(1);
}

MainGame::MainGame()
{
	_window = nullptr; // nullptr?
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();

	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

	gameLoop();
}

void MainGame::initSystems()
{
	//	Initialize SDL, window, check for loading errors and set background color
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("The Legend of Nedla", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL); // If the window creation fails it returns false
	
	if (_window == nullptr)
	{
		fatalError("SDL Window could not be created.");
	}

	SDL_GLContext glContex = SDL_GL_CreateContext(_window);
	if (glContex == nullptr)
	{
		fatalError("SDL_GL context could not be created.");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		fatalError("GLEW IS NOT OK");
	}
	
	
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f); //Set background color
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) //Why is this a call by reference?
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << "ayy lmao " << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;
		}
	}
}

void MainGame::drawGame()
{
	glClearDepth(1.0); //Set base depth to 1.0
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //This line combines the two bits of data into one to save space. The color and depth buffers are cleared
	
	_sprite.draw();

	SDL_GL_SwapWindow(_window); //Swap between active and buffer window
}