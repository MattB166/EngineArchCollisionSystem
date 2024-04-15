#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
public:
	/// @brief Creates a collider for a 2D Square Object, and stores its callback function in here.
	/// @param x 
	/// @param y 
	/// @param width 
	/// @param height 
	/// @param callback 
	BoxCollider(float& x, float& y, float& width, float& height, std::function<void(Collider* col)> callback);
	float* width;
	float* height;
private:
	
	
};

