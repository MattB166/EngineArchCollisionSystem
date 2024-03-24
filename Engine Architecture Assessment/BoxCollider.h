#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
	float width;
	float height;
	virtual void SetPosition(float NewX, float NewY) override;
};

