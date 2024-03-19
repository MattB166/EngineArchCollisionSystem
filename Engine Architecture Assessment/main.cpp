#include <iostream>
#include "Game.h"
#include "SDL.h"


bool Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise" << std::endl;
		return true;
	}
}
int main(int argc, char* argv[])
{

	if (Initialise())
	{
		std::cout << "application failed to open" << std::endl;
		return -1;
	}

	Game::instance()->Run();

	SDL_Quit();

	return 0; 
}