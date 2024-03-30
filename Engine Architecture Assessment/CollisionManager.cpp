#include "CollisionManager.h"

CollisionManager* CollisionManager::_instance = nullptr; 

/// <summary>
/// Compares two box colliders against each other for collision. If a collision has occured then true is returned.
/// </summary>
/// <param name="collider1"></param>
/// <param name="Collider2"></param>
/// <returns></returns>
bool CollisionManager::SquareCollision(BoxCollider* collider1, BoxCollider* Collider2)
{
	return false;
}
/// <summary>
/// Compares two circle colliders against each other for collision. If a collision has occured then true is returned.
/// </summary>
/// <returns></returns>
bool CollisionManager::CircleCollision()
{
	return false;
}

/// <summary>
/// Compares a box collider against a circle collider for collision. If a collision has occured then true is returned. 
/// </summary>
/// <returns></returns>
bool CollisionManager::CircleRectCollision()
{
	return false;
}

/// <summary>
/// Checks for collision between Objects and the bounds of the 2D world. If a collision has occured then true is returned. 
/// </summary>
/// <returns></returns>
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

/// <summary>
/// Checks between all actively set colliders to compare against each other. If any collision is detected via any method, the colliders callbacks are triggered. 
/// </summary>
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
				if (SquareCollision(bCol, bCol1))
				{
					bCol->callback;
					bCol1->callback;
				}
			}
			if (col->GetColliderType() == SquareCollider && col1->GetColliderType() == CircleCollider)
			{
				BoxCollider* bCol = dynamic_cast<BoxCollider*>(col);
				///circle collider here 
			}

		}
	}
}

/// <summary>
/// Called every frame to iterate through collider checks. 
/// </summary>
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


/// <summary>
/// Add a collider to the collision system list, to be checked for collisions. 
/// </summary>
/// <param name="collider"></param>
void CollisionManager::AddCollider(Collider* collider)
{
	colliders.push_back(collider);
	
	std::cout << "ADDED COLLIDER TO LIST" << std::endl; 

}
  