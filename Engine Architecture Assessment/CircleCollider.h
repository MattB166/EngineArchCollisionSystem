#pragma once
#include "Collider.h"
class CircleCollider : public Collider
{
public:
		CircleCollider(float& x, float& y, float& radius, std::function<void()> callback);
		float* radius;
private:
	
	/*float* x;
		float* y;*/
};

