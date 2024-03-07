#include "Game.h"


void Game::Run()
{
	SpawnObjects(Circle,3);
	
	isRunning = true;
	while (isRunning)
	{
		Update(); 
		
	}
}

void Game::Initialise()
{

}

void Game::Update()
{
	//std::cout << "Running" << std::endl; 
	///gameobject update
	//collision update 
	
}

void Game::SpawnObjects(ObjectType type, int amount)
{
	///run through and spawn some squares and circles 
	for (int i = 0; i < amount; ++i)
	{
		GameObject* obj = new GameObject(type);
		objects.push_back(obj);
	}
	std::cout << "Spawned " << amount << " of " << GameObject::ObjectTypeToString(type);

	
}
