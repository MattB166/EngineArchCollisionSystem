#include "Game.h"

void Game::Run()
{
	if (Initialise())
	{
		std::cout << "Application failed to initialise. Quitting... " << std::endl;
		return;
	}
	//load textures here and assign them to the shapes 
	
	SpawnObjects(Circle, 3);
	
	isRunning = true;
	while (isRunning)
	{
		Update(); 
		
	}
	CleanUp();
}

bool Game::Initialise()
{
	int iwindowflag = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_FULLSCREEN_DESKTOP;
	g_sdlWindow = SDL_CreateWindow("Engine Architecture Assessment", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, NULL);

	//error checking
	if (g_sdlWindow == nullptr)
	{
		std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl;
		return true;
	}

	g_sdlRenderer = SDL_CreateRenderer(g_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	if (g_sdlRenderer == nullptr)
	{
		std::cout << "Failed to create renderer. SDL error: " << SDL_GetError() << std::endl;
		return true;

	}
	return false;
}

void Game::CleanUp()
{
	SDL_DestroyRenderer(g_sdlRenderer);
	SDL_DestroyWindow(g_sdlWindow);
	SDL_Quit();
}

SDL_Texture* Game::LoadTexture(const char* filename)
{
	//load door bmp as a surface		
	SDL_Surface* image = IMG_Load(filename);
	if (image == nullptr)
	{
		std::cout << "Failed to load " << filename << ". SDL ERROR: " << IMG_GetError() << std::endl;
	}

	//convert surface of loaded bmp into a texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(g_sdlRenderer, image);
	if (texture == nullptr)
	{
		std::cout << "Failed to create texture from surface" << std::endl;
	}

	//free surface
	SDL_FreeSurface(image);


	return texture;
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
