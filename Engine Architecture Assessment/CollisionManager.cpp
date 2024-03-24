#include "CollisionManager.h"

CollisionManager* CollisionManager::_instance = nullptr; 
bool CollisionManager::SquareCollision(BoxCollider* collider1, BoxCollider* Collider2)
{
	return false;
}

bool CollisionManager::CircleCollision()
{
	return false;
}

bool CollisionManager::BoundsCollision()
{
	return false;
}

void CollisionManager::CreateCollider(float x,float y,float w,float h, float rotation, float radius)
{
	std::cout << "creating collider for listener" << std::endl; 
	///initialise new collider here 
}

void CollisionManager::HandleCollision()
{

}

void CollisionManager::UpdatePositions()
{
	//std::cout << "Updating positions of colliders" << std::endl; 
}

void CollisionManager::Update()
{

}
