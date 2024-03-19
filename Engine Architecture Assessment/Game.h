#pragma once
#include <iostream>
#include "SDL.h"
#include <list>
#include "SDL_image.h"
#include "GameObject.h"
class GameObject;
enum ObjectType;
class Game
{
public:
	static Game* instance() { return _instance != nullptr ? _instance : _instance = new Game(); }
	void Run();
	bool Initialise();
	void CleanUp();
	SDL_Renderer* GetRenderer();
	SDL_Texture* LoadTexture(const char* filename);

private:
	static Game* _instance;
	std::list<GameObject*> objects;  ///iterate through and add colliders 
	SDL_Window* g_sdlWindow;
	SDL_Renderer* g_sdlRenderer;
	void Update();
	void SpawnObjects(ObjectType type, int amount, SDL_Renderer* renderer, SDL_Texture* texture);
	bool isRunning;
	static float WorldX;
	static float WorldY;
	// pointer reference to event manager/handler 

	
};

///make a singleton and have a getRenderer function rather than constantly passing by parameter 