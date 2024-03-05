#include "Game.h"

void Game::Run()
{
	isRunning = true;
	while (isRunning)
	{
		Update(); 
	}
}

void Game::Update()
{
	std::cout << "Running" << std::endl; 
}
