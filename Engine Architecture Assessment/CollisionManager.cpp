#include "CollisionManager.h"
#include "EventManager.h"

//CollisionManager* CollisionManager::_instance = nullptr;
std::list<Collider*> CollisionManager::colliders;

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

bool CollisionManager::CircleCollision(CircleCollider* collider1, CircleCollider* collider2)
{
	float dx = *collider1->x - *collider2->x;
	float dy = *collider1->y - *collider2->y;
	float distance = sqrt((dx * dx) + (dy * dy));
	

	if (distance <= *collider1->radius + *collider2->radius)
	{
		return true;
	}

	return false;

}




bool CollisionManager::CircleRectCollision(CircleCollider* circ, BoxCollider* box)
{
	float circleX = *circ->x;
	float circleY = *circ->y;
	float radius = *circ->radius;

	float boxX = *box->x;
	float boxY = *box->y;
	float boxWidth = *box->width;
	float boxHeight = *box->height;

	float ClosestX;
	float ClosestY;

	if (circleX < boxX)
	{
		ClosestX = boxX;
	}
	else if (circleX > boxX + boxWidth)
	{
		ClosestX = boxX + boxWidth;
	}
	else
	{
		ClosestX = circleX;
	}

	if (circleY < boxY)
	{
		ClosestY = boxY;
	}
	else if (circleY > boxY + boxHeight)
	{
		ClosestY = boxY + boxHeight;
	}
	else
	{
		ClosestY = circleY;
	}
	
	int deltaX = ClosestX - circleX;
	int deltaY = ClosestY - circleY;
	if ((deltaX * deltaX) + (deltaY * deltaY) < radius * radius)
	{
		return true;
	}
	return false;
}

/// @brief 
/// @return 
bool CollisionManager::BoundsCollision()
{
	return false;
}


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
				else if (SquareCollision(bCol, bCol1))
				{
					
					bCol->callback(bCol1); ////possibly change this to carry 2 params so that each obj can check whether it is them ? 
					bCol1->callback(bCol);
					
					EventManager::ProduceEvent(EventType::Collision, bCol1, bCol);
					
					
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
				else if (CircleRectCollision(cCol, bCol))
				{

					bCol->callback(cCol);
					cCol->callback(bCol);
					
					
				}

				
			}
			 if (col->GetColliderType() == CircCollider && col1->GetColliderType() == CircCollider)
			{
				
				CircleCollider* cCol = dynamic_cast<CircleCollider*>(col);
				CircleCollider* cCol1 = dynamic_cast<CircleCollider*>(col1);
				if (cCol == nullptr || cCol1 == nullptr)
				{
					
					continue;
				}
				else if (CircleCollision(cCol, cCol1))
				{
					
					cCol->callback(cCol1);
					cCol1->callback(cCol);
					
				}
			}

		}
	}
}


void CollisionManager::Update()
{
	HandleCollision();


}



void CollisionManager::AddCollider(Collider* collider)
{
	colliders.push_back(collider);

	
	

}

void CollisionManager::RemoveCollider(Collider* collider)
{
	colliders.remove(collider);
}

void CollisionManager::CleanUp()
{
	for (auto it = colliders.begin(); it != colliders.end(); ++it)
	{
		delete *it;
		*it = nullptr;
	}
}
