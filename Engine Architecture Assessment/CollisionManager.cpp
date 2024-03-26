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

bool CollisionManager::CircleRectCollision()
{
	return false;
}

bool CollisionManager::BoundsCollision()
{
	return false;
}

//void CollisionManager::CreateCollider(float &x,float &y,float &w,float &h)
//{
//
//	std::cout << "added collider " << std::endl; 
//	
//}

void CollisionManager::HandleCollision()
{

}

void CollisionManager::UpdatePositions()
{
	
}

void CollisionManager::Update()
{
	for (auto it = colliders.begin(); it != colliders.end(); ++it)
	{
		Collider* col = *it;

		if (col->GetColliderType() == SquareCollider)
		{
			std::cout << "Found a square collider" << std::endl;
		}
	}
}

void CollisionManager::AddCollider(Collider* collider)
{
	colliders.push_back(collider);
	//std::cout << "ADDED COLLIDER TO LIST" << std::endl; 
}
