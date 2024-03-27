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
	for (auto it = colliders.begin(); it != colliders.end(); ++it)
	{
		for (auto ij = std::next(it, 1); ij != colliders.end(); ++ij)
		{
			Collider* col = *it;
			Collider* col1 = *ij;
			if (col->GetColliderType() == SquareCollider && col1->GetColliderType() == SquareCollider)
			{
				BoxCollider* bCol = dynamic_cast<BoxCollider*>(col);
				BoxCollider* bCol1 = dynamic_cast<BoxCollider*>(col1);
				SquareCollision(bCol, bCol1);
			}
			if (col->GetColliderType() == SquareCollider && col1->GetColliderType() == CircleCollider)
			{
				BoxCollider* bCol = dynamic_cast<BoxCollider*>(col);
				///circle collider here 
			}

		}
	}
}

void CollisionManager::UpdatePositions()
{
	
}

void CollisionManager::Update()
{
	/*for (auto it = colliders.begin(); it != colliders.end(); ++it)
	{
		Collider* col = *it;

		if (col->GetColliderType() == SquareCollider)
		{
			BoxCollider* bCol = dynamic_cast<BoxCollider*>(col); ///i have downcasted to get access to their derived classes.
			
			///now need to compare against all other colliders and move the iterator up 

			                                                 
	
		}

	}*/
	
	
}


void CollisionManager::AddCollider(Collider* collider, std::function<void()> func)
{
	colliders.push_back(collider);
	std::cout << "ADDED COLLIDER TO LIST" << std::endl; 

}
  