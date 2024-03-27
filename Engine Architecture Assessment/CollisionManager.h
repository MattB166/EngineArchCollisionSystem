#pragma once
#include "Collider.h"
#include <iostream>
#include "BoxCollider.h"
#include <list>
#include <functional>
#include <map>
class CollisionManager   
{

public:
	static CollisionManager* instance() { return _instance != nullptr ? _instance : _instance = new CollisionManager(); }
	static bool SquareCollision(BoxCollider* collider1, BoxCollider* collider2);  /* aabb example for basic box collision.
	if both axis overlap the boxes overlap*/
	
	static bool CircleCollision();

	static bool CircleRectCollision();

	static bool BoundsCollision();  
	void HandleCollision();
	void UpdatePositions();
	void Update();
	void AddCollider(Collider* collider, std::function<void()> func);

private:
	static CollisionManager* _instance;
	std::list<Collider*> colliders;
	
};

