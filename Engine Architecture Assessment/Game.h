#pragma once
#include <iostream>
#include <list>
#include "SDL_image.h"
#include "GameObject.h"
class Game
{
public:
	void Run();
	bool Initialise();
	void CleanUp();
	SDL_Texture* LoadTexture(const char* filename);

private:
	std::list<GameObject*> objects;
	SDL_Window* g_sdlWindow;
	SDL_Renderer* g_sdlRenderer;
	void Update();
	void SpawnObjects(ObjectType type, int amount);
	bool isRunning;
	// pointer reference to event manager/handler 
};

