#pragma once
#include "GameObject.h"
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
	 void Draw() override;
	 void OnCollisionNotify(Collider* col) override;
	 void OnOtherObjectCollisionNotify(Collider* col, Collider* col1) override;

private:
	float radius;
	Colour DrawColour;
	void RandomColour();
};

