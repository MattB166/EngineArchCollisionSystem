#include "BoxCollider.h"



BoxCollider::BoxCollider(float& x, float& y, float& width, float& height, std::function<void()> callback)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height; ///should be able to track these values inside collision manager now 
	SetColliderType(SquareCollider);
	this->callback = callback;
	

}

