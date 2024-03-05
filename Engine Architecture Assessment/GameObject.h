#pragma once
#include "SDL.h"
class GameObject
{
public:
	GameObject(SDL_Texture* FirstTexture, SDL_Texture* SecondTexture);
	void Update();


private:
	void ChangeTexture();
	float width;
	float height;
	SDL_Texture* Maintexture = nullptr;
	SDL_Texture* SecondaryTexture = nullptr;
};

