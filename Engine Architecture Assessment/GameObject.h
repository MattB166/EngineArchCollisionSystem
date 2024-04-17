#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
#include "Game.h"
#include "Vector2.h"
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



class GameObject

{
public:
	GameObject(ObjectType type);
	GameObject(Parameters params);
	GameObject();
	~GameObject();
	
	void Update();
	static std::string ObjectTypeToString(ObjectType type);
	Vector2 GetPosition();
	
	std::string getName();
	ObjectType GetType();
	
	virtual void OnCollisionNotify(Collider* col);
	virtual void OnOtherObjectCollisionNotify(Collider* col, Collider* col1);
protected:
    virtual void ChangeTexture();
	virtual void Draw();
	void SetObjectPosition();
	void Movement(float deltaTime);
	
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
	bool movementStopped = false; 
	SDL_Renderer* Renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Texture* MainTexture = nullptr;
	SDL_Texture* SecondaryTexture = nullptr;
};