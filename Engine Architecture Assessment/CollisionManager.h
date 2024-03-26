#pragma once
#include "Collider.h"
#include <iostream>
#include "BoxCollider.h"
#include <list>
class CollisionManager   
{

public:
	static CollisionManager* instance() { return _instance != nullptr ? _instance : _instance = new CollisionManager(); }
	static bool SquareCollision(BoxCollider* collider1, BoxCollider* collider2);  /* aabb example for basic box collision.
	if both axis overlap the boxes overlap*/
	
	static bool CircleCollision();

	static bool CircleRectCollision();

	static bool BoundsCollision(); ////checking whether objects bouncing off walls 
	void HandleCollision();
	void UpdatePositions();
	void Update();
	void AddCollider(Collider* collider);

private:
	static CollisionManager* _instance;
	std::list<Collider*> colliders;
	///way to generate colliders from here inside each object and set flags to whether they are active or not, so can showcase the system 
};

