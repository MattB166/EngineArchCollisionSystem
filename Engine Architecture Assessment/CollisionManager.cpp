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

void CollisionManager::CreateCollider(float &x,float &y,float &w,float &h)
{

	std::cout << "added collider " << std::endl; 
	
}

void CollisionManager::HandleCollision()
{

}

void CollisionManager::UpdatePositions()
{
	
}

void CollisionManager::Update()
{

}
