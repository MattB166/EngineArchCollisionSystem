#pragma once
class CollisionManager  ///class to create collision events 
{

public:
	static CollisionManager* instance() { return _instance != nullptr ? _instance : _instance = new CollisionManager(); }
	static bool SquareCollision(/*box colliders as parameters here*/);  /* aabb example for basic box collision.
	if both axis overlap the boxes overlap*/
	
	static bool CircleCollision(/*radii and base x and y's set here*/);

private:
	static CollisionManager* _instance;
};

////also need a way to assign colliders to all generated objects 