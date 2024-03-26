#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include "Game.h"
#include "Vector2.h"
#include "EventManager.h"
#include "CollisionManager.h"
#include "IObserver.h"
enum ObjectType
{
	ShapeSquare,
	ShapeCircle
};
struct Parameters 
{
	SDL_Texture* texture;
	SDL_Texture* SecondTexture;
	SDL_Renderer* renderer;
	ObjectType type;

	Parameters(SDL_Texture* texture,
		SDL_Texture* SecondTexture,
		SDL_Renderer* renderer,
		ObjectType type);
};

struct CircleParameters
{
	int32_t radius;
};
//struct ObjectRect
//{
//	float x, y, w, h;  ///might need to be pointers 
//};
class GameObject:public IObserver
{
public:
	GameObject(ObjectType type);
	GameObject(Parameters params);
	~GameObject();
	
	void Update();
	static std::string ObjectTypeToString(ObjectType type);
	Vector2 GetPosition();
	
	std::string getName();
	ObjectType GetType();
	
	void Observe() override;
	//void OnCollisionNotify(const GameObject& obj) override;

protected:
	void ChangeTexture();
	virtual void Draw();
	void SetObjectPosition();
	void RandomMovement(float deltaTime);
	
	std::string name;
	ObjectType Object;
	Vector2 pos;
	Vector2 movePos;
	//ObjectRect information;
	float speed = 60;
	float width = 40;
	float height = 40;
	float rotation = 0;
	float radius;
	bool arrived = true;
	bool textureActive = true;
	bool movementStopped = false; //will be flagged true when collision occurs and movement will temporarily be handled elsewhere 
	SDL_Renderer* Renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Texture* MainTexture = nullptr;
	SDL_Texture* SecondaryTexture = nullptr;
};