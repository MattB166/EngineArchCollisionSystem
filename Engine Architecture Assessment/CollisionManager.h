#pragma once
class CollisionManager   
{

public:
	static CollisionManager* instance() { return _instance != nullptr ? _instance : _instance = new CollisionManager(); }
	static bool SquareCollision(/*box colliders as parameters here*/);  /* aabb example for basic box collision.
	if both axis overlap the boxes overlap*/
	
	static bool CircleCollision(/*radii and base x and y's set here*/);

	static bool BoundsCollision(); ////checking whether objects bouncing off walls 
	void CreateCollider();

private:
	static CollisionManager* _instance;
	//list of colliders or gameobjects 
	///way to generate colliders from here inside each object. so also need a collider class 
};

////also need a way to assign colliders to all generated objects 