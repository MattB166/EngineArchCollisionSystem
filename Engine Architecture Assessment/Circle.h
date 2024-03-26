#pragma once
#include "GameObject.h"
struct CircleParameters
{
	int32_t radius;

	CircleParameters(int32_t radius);
};
class Circle:public GameObject
{
public:
	Circle(Parameters params, CircleParameters param);
	virtual void Draw() override;

private:
	float radius;
};

