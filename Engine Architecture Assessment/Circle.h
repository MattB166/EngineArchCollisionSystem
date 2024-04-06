#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
struct CircleParameters
{
	float radius;

	CircleParameters(float radius);
};
class Circle:public GameObject
{
public:
	Circle(Parameters params, CircleParameters param);
	CircleCollider* collider = nullptr;
	virtual void Draw() override;

private:
	float radius;
};

