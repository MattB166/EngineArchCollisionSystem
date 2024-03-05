#include <iostream>
#include "Game.h"
#include "SDL.h"


void Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise" << std::endl;
	}
}
int main(int argc, char* argv[])
{

	Initialise();

	Game mygame; 
	mygame.Run();

	SDL_Quit();

	return 0; 
}