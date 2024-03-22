#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include "Game.h"
#include "Vector2.h"
#include "EventManager.h"
#include "IObserver.h"
enum ObjectType
{
	Square,
	Circle
};
struct Parameters 
{
	SDL_Texture* texture;
	SDL_Texture* SecondTexture;
	SDL_Renderer* renderer;
	ObjectType type;


};
struct ObjectRect
{
	float x, y, w, h;
};
class GameObject:public IObserver
{
public:
	GameObject(ObjectType type);
	GameObject(Parameters params);
	~GameObject();
	
	void Update();
	static std::string ObjectTypeToString(ObjectType type);
	std::string getName();
	//void Spawn(ObjectType type);
	void Observe() override;

private:
	void ChangeTexture();
	void Draw();
	void SetObjectPosition();
	void RandomMovement(float deltaTime);
	void OnCollisionEnter(/*Collider here*/);
	///need movement and need to work out drawing circles with textures too 
	std::string name;
	ObjectType Object;
	Vector2 pos;
	Vector2 movePos;
	float speed = 60;
	float width = 40;
	float height = 40;
	float rotation = 0;
	bool arrived = true;
	bool textureActive = true;
	bool movementStopped = false; //will be flagged true when collision occurs and movement will temporarily be handled elsewhere 
	SDL_Renderer* Renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Texture* MainTexture = nullptr;
	SDL_Texture* SecondaryTexture = nullptr;
};