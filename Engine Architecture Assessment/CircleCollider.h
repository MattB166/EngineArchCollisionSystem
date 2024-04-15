#pragma once
#include "Collider.h"
class CircleCollider : public Collider
{
public:
	/// @brief Creates a collider for a 2D Circular Object, and stores its callback function in here.
	/// @param x 
	/// @param y 
	/// @param radius 
	/// @param callback 
		CircleCollider(float& x, float& y, float& radius, std::function<void(Collider* col)> callback);
		float* radius;
private:
	
	
};

