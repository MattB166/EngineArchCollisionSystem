#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
class Square : public GameObject
{
public:
	Square(Parameters params);
	BoxCollider* collider = nullptr; //use this to send into collision 
	////add virtual void draw 
};

