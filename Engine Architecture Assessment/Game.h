#pragma once
#include <iostream>
#include "SDL.h"
#include <list>
#include "SDL_image.h"
#include "GameObject.h"
#include "CollisionManager.h"

#include "Time.h"
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
	static float WorldX;
	static float WorldY;

private:
	static Game* _instance;
	std::list<GameObject*> objects; 
	SDL_Window* g_sdlWindow;
	SDL_Renderer* g_sdlRenderer;
	void Update();
	void SpawnObjects(ObjectType type, int amount, SDL_Renderer* renderer, SDL_Texture* FirstTexture, SDL_Texture* SecondTexture);
	bool isRunning;


	

	
};

