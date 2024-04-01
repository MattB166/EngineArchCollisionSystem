#pragma once
#include "Collider.h"
#include <iostream>
#include "BoxCollider.h"
#include "CircleCollider.h"
#include <list>
#include <functional>
#include <map>
class CollisionManager   
{

public:
	static CollisionManager* instance() { return _instance != nullptr ? _instance : _instance = new CollisionManager(); }
	static bool SquareCollision(BoxCollider* collider1, BoxCollider* collider2);  
	
	static bool CircleCollision(CircleCollider* collider1, CircleCollider* collider2);

	static bool CircleRectCollision(CircleCollider* circ, BoxCollider* box);

	static bool BoundsCollision();  
	void HandleCollision();
	void Update();
	void AddCollider(Collider* collider);

private:
	static CollisionManager* _instance;
	std::list<Collider*> colliders;
	
};

