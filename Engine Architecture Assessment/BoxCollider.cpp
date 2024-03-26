#include "BoxCollider.h"



BoxCollider::BoxCollider(float& x, float& y, float& width, float& height)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height; ///should be able to track these values inside collision manager now 
	SetColliderType(SquareCollider);
	
	

}
