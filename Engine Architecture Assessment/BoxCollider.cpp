#include "BoxCollider.h"



BoxCollider::BoxCollider(float& x, float& y, float& width, float& height, std::function<void(Collider* col)> callback)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height; 
	SetColliderType(SquareCollider);
	this->callback = callback;

	

}

