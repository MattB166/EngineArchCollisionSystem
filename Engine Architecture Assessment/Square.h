#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
class Square : public GameObject
{
public:
	Square(Parameters params);
	~Square();
	BoxCollider* collider  =nullptr; 
	
	float width = 40;
	float height = 40;
private:
};

