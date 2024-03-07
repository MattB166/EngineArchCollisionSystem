#pragma once
#include <iostream> 
#include <list>
#include "GameObject.h"
class Game
{
public:
	void Run();
	void Initialise();

private:
	std::list<GameObject*> objects;
	SDL_Window* g_sdlWindow;
	SDL_Renderer* g_sdlRenderer;
	void Update();
	void SpawnObjects(ObjectType type, int amount);
	bool isRunning;
	// pointer reference to event manager/handler 
};

