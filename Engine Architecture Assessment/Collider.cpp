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

