#include "Collider.h"

Collider::Collider()
{
	isActive = true;
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

bool Collider::GetState()
{
	return isActive;
}

void Collider::SetState(bool state)
{
	isActive = state;
}

