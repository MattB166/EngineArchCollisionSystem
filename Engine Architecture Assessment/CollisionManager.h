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
	
	static bool CircleCollision(/*radii and base x and y's set here*/);

	static bool BoundsCollision(); ////checking whether objects bouncing off walls 
	void CreateCollider(float &x,float &y,float &w, float &h);
	void HandleCollision();
	void UpdatePositions();
	void Update();

private:
	static CollisionManager* _instance;
	std::list<Collider*> colliders;
	///way to generate colliders from here inside each object and set flags to whether they are active or not, so can showcase the system 
};

////also need a way to assign colliders to all generated objects 