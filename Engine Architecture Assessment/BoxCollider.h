#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
public:
	BoxCollider(float& x, float& y, float& width, float& height, std::function<void()> callback);
private:
	float* width;
	float* height;
	/*float* x;
	float* y;
	*/
};

