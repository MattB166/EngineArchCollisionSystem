#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include "Vector2.h"
enum ObjectType
{
	Square,
	Circle
};
class GameObject
{
public:
	GameObject(ObjectType type);
	GameObject(SDL_Texture* FirstTexture, SDL_Texture* SecondTexture, SDL_Renderer* renderer, ObjectType type);
	void Draw(SDL_Renderer* renderer);
	void Update();
	static std::string ObjectTypeToString(ObjectType type);
	//void Spawn(ObjectType type);


private:
	void ChangeTexture();
	std::string name;
	ObjectType Object;
	Vector2 pos;
	float width;
	float height;
	SDL_Renderer* Renderer;
	SDL_Texture* texture = nullptr;
	SDL_Texture* Maintexture = nullptr;
	SDL_Texture* SecondaryTexture = nullptr;
};

