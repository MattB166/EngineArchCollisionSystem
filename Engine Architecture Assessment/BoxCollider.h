#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
public:
	BoxCollider(float& x, float& y, float& width, float& height);
private:
	float* width;
	float* height;
	/*float* x;
	float* y;
	*/
};

