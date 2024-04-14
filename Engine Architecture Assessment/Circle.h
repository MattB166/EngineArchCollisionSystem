#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
struct Colour
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};
struct CircleParameters
{
	float radius;

	CircleParameters(float radius);
};
class Circle:public GameObject
{
public:
	Circle(Parameters params, CircleParameters param);
	~Circle();
	CircleCollider* collider = nullptr;
	virtual void Draw() override;
private:
	float radius;
	Colour mainColour;
	Colour secondaryColour;
};

