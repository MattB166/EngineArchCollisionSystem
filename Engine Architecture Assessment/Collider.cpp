#include "Collider.h"

Collider::Collider()
{

}

Collider::~Collider()
{

}

void Collider::SetColliderType(Type type)
{
	this->ColliderType = type;
}


Type Collider::GetColliderType()
{
	return ColliderType;
}


void Collider::SetPosition(ColliderVector2 pos)
{
	this->x = &pos.x;
	this->y = &pos.y;
}

ColliderVector2 Collider::GetPosition()
{
	return position;
}

