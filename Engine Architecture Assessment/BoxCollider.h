#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
public:
	BoxCollider(float& x, float& y, float& width, float& height, std::function<void(Collider* col)> callback);
	float* width;
	float* height;
private:
	
	/*float* x;
	float* y;
	*/
};

