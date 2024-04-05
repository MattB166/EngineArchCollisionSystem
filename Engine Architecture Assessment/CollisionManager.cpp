#include "CollisionManager.h"

CollisionManager* CollisionManager::_instance = nullptr; 

/// <summary>
/// Compares two box colliders against each other for collision. If a collision has occured then true is returned.
/// </summary>
/// <param name="collider1"></param>
/// <param name="Collider2"></param>
/// <returns></returns>
bool CollisionManager::SquareCollision(BoxCollider* collider1, BoxCollider* collider2)
{

	if (collider1->x == nullptr || collider1->y == nullptr || collider1->width == nullptr || collider1->height == nullptr)
	{
		return false; 
	}

	float MinX1 = *collider1->x;
	float MaxX1 = *collider1->x + *collider1->width;

	float MinY1 = *collider1->y;
	float MaxY1 = *collider1->y + *collider1->height;

	float MinX2 = *collider2->x;
	float MaxX2 = *collider2->x + *collider2->width;

	float MinY2 = *collider2->y;	
	float MaxY2 = *collider2->y + *collider2->height;



	return MaxX1 > MinX2 && MinX1 < MaxX2 && MaxY1 > MinY2 && MinY1 < MaxY2;
}
/// <summary>
/// Compares two circle colliders against each other for collision. If a collision has occured then true is returned.
/// </summary>
/// <returns></returns>
bool CollisionManager::CircleCollision(CircleCollider* collider1, CircleCollider* collider2)
{
	float dx = *collider1->x - *collider2->x;
	float dy = *collider1->y - *collider2->y;
	float distance = sqrt((dx * dx) + (dy * dy));

	if (distance < *collider1->radius + *collider2->radius)
	{
		return true;
	}
	else
	return false;
	
}

/// <summary>
/// Compares a box collider against a circle collider for collision. If a collision has occured then true is returned. 
/// </summary>
/// <returns></returns>
bool CollisionManager::CircleRectCollision(CircleCollider* circ, BoxCollider* box)
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
				if (bCol == nullptr || bCol1 == nullptr)
				{
					continue;
				}
				if (SquareCollision(bCol, bCol1))
				{
					//std::cout << "COLLISION DETECTED" << std::endl;	
					bCol->callback(bCol1);
					bCol1->callback(bCol);
				}
			}
			if (col->GetColliderType() == SquareCollider && col1->GetColliderType() == CircCollider)
			{
				BoxCollider* bCol = dynamic_cast<BoxCollider*>(col);
				CircleCollider* cCol = dynamic_cast<CircleCollider*>(col1); 
				if (bCol == nullptr || cCol == nullptr)
				{
					continue;
				}
				if (CircleRectCollision(cCol, bCol))
				{

					bCol->callback(cCol);
					cCol->callback(bCol);
				}
				
				///circle collider here 
			}
			if (col->GetColliderType() == CircCollider && col1->GetColliderType() == CircCollider)
			{
				CircleCollider* cCol = dynamic_cast<CircleCollider*>(col);
				CircleCollider* cCol1 = dynamic_cast<CircleCollider*>(col1);
				if (CircleCollision(cCol, cCol1))
				{
					cCol->callback(cCol1);
					cCol1->callback(cCol);
				}
			}

		}
	}
}

/// <summary>
/// Called every frame to iterate through collider checks. 
/// </summary>
void CollisionManager::Update()
{
	HandleCollision();
	
	
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
  