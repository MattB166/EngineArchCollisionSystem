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
	return Type();
}

void Collider::SetPosition(Vector2 pos)
{
	this->x = &pos.x;
	this->y = &pos.y;
}

Vector2 Collider::GetPosition()
{
	return position;
}

