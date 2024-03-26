#include "Game.h"
#include "Square.h"

Game* Game::_instance = nullptr;
float Game::WorldX = 800;
float Game::WorldY = 600;

void Game::Run()
{
	if (Initialise())
	{
		std::cout << "Application failed to initialise. Quitting... " << std::endl;
		return;
	}
	//load textures here and assign them to the shapes 
	SDL_Texture* MagicTexture = SDL_CreateTexture(g_sdlRenderer, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_TARGET, 64, 64);
	SDL_SetRenderTarget(g_sdlRenderer, MagicTexture);
	SDL_SetRenderDrawColor(g_sdlRenderer, 255, 0, 0, 255);
	SDL_RenderClear(g_sdlRenderer);
	SDL_SetRenderTarget(g_sdlRenderer, NULL);
	SDL_Texture* SecondTexture = SDL_CreateTexture(g_sdlRenderer, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_TARGET, 64, 64);
	SDL_SetRenderTarget(g_sdlRenderer, SecondTexture);
	SDL_SetRenderDrawColor(g_sdlRenderer, 255, 255, 255, 255);
	SDL_RenderClear(g_sdlRenderer);
	SDL_SetRenderTarget(g_sdlRenderer, NULL);
	
	SpawnObjects(ObjectType::ShapeSquare, 3,g_sdlRenderer, MagicTexture,SecondTexture);
	
	
	isRunning = true;
	
	while (isRunning)
	{
		SDL_SetRenderDrawColor(g_sdlRenderer, 19, 47, 209, 255);
		SDL_RenderClear(g_sdlRenderer);
		Update(); 
		SDL_RenderPresent(g_sdlRenderer);
	}
	SDL_DestroyTexture(MagicTexture);
	SDL_DestroyTexture(SecondTexture);
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

SDL_Renderer* Game::GetRenderer()
{
	return g_sdlRenderer;
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
	Time::instance()->UpdateDeltaTime();
	std::list<GameObject*>::iterator iter;
	iter = this->objects.begin();

	for (std::list<GameObject*>::const_iterator iter = this->objects.begin(), end = this->objects.end();iter!=end;++iter)
	{
		(*iter)->Update();
	}
	//EventManager::instance()->UpdateCollisionSystem(); ///shouldnt be doing inside event manager. do in game class 
	CollisionManager::instance()->Update();
	//std::cout << Time::instance()->GetDeltaTime() << std::endl;
	
}

void Game::SpawnObjects(ObjectType type, int amount,SDL_Renderer* renderer, SDL_Texture* FirstTexture, SDL_Texture* SecondTexture)
{
	if (type == ObjectType::ShapeSquare)
	{
		for (int i = 0; i < amount; ++i)
		{
			Parameters params(FirstTexture, SecondTexture, renderer, type);
			Square* square = new Square(params);
			objects.push_back(square);
		}
		std::cout << "Spawned " << amount << " of " << GameObject::ObjectTypeToString(type);
	}
	else if (type == ShapeCircle)
	{

	}
	

	
}
