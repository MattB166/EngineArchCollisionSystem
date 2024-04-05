#include "BoxCollider.h"


/// <summary>
/// Instantiation of Box Collider sets its type for the collision manager to work with, and its callback function.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="callback"></param>
BoxCollider::BoxCollider(float& x, float& y, float& width, float& height, std::function<void(Collider* col)> callback)
{
	this->x = &x;
	this->y = &y;
	this->width = &width;
	this->height = &height; ///should be able to track these values inside collision manager now 
	SetColliderType(SquareCollider);
	this->callback = callback;
	

}

