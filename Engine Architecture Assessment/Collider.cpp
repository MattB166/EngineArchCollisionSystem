#include "Collider.h"

Collider::Collider()
{

}

Collider::~Collider()
{

}

/// @brief Determines the type of collider this object is.
/// @param type(Square, Circle)
void Collider::SetColliderType(Type type)
{
	this->ColliderType = type;
}

/// @brief Returns the type of this collider. 
/// @return collider
Type Collider::GetColliderType()
{
	return ColliderType;
}

/// @brief Initialises the position of this collider
/// @param pos 
void Collider::SetPosition(ColliderVector2 pos)
{
	this->x = &pos.x;
	this->y = &pos.y;
}
/// @brief Returns the Vector2 Position of this collider
/// @return position
ColliderVector2 Collider::GetPosition()
{
	return position;
}

