#include "CircleCollider.h"

CircleCollider::CircleCollider(float& x, float& y, float& radius, std::function<void()> callback)
{
	this->x = &x;
	this->y = &y;
	this->radius = &radius;
	this->callback = callback;
	SetColliderType(CircCollider);
}
