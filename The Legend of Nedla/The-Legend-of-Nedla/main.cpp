/***************************************************************************************
*	The Legend of Nedla
*	An adventure RPG
*
*	Made by Nedla and CCiaran
*	06/01/2016
****************************************************************************************/

/*	
	I have no idea what the fuck I'm doing. I followed some youtube tutorial that told me to add SDL which makes graphics and shit a lot easier.

	Some quesions :
		It told me to do a whole bunch of shit like link libraries and dlls and includes but I don't know what that means, what they do, what the differences are?
		I was told to add 'glew' which is some kind of 'OpenGL extension wrangler' sure, but is OpenGL IN glew ? Why can't I just get OpenGL?
*/

#include <iostream>

#include "MainGame.h"
#include "Sprite.h"

//	Apparently when you run SDL.h it takes custody of the real main function.\
//	You can call this one in the 'source' whatever you want but you need to add those arguments because\
//	the real main is sending over some shit this way.
int main(int argc, char** argv)	// char* is an array of characters, some people like to call them 'strings'. And then you need another * because uh.. its an array of strings? yeah.
{
	MainGame mainGame;
	mainGame.run();

	return 0;
}