#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include "Game.h"
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
	~GameObject();
	void Draw();
	void Update();
	static std::string ObjectTypeToString(ObjectType type);
	//void Spawn(ObjectType type);


private:
	void ChangeTexture();
	void SetObjectPosition();
	void RandomMovement();
	///need movement and need to work out drawing circles with textures too 
	std::string name;
	ObjectType Object;
	Vector2 pos;
	float width = 40;
	float height = 40;
	float rotation = 0;
	SDL_Renderer* Renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Texture* Maintexture = nullptr;
	SDL_Texture* SecondaryTexture = nullptr;
};