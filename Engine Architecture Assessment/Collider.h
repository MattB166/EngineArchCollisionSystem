#pragma once
#include "Vector2.h"
#include <functional>
enum Type
{
	SquareCollider,
	CircCollider,
};
class Collider
{
public:
	Collider();
	virtual ~Collider();
	void SetColliderType(Type type);
	Type GetColliderType();
	void SetPosition(Vector2 pos);
	Vector2 GetPosition();
	bool enabled = true;
	float* x;
	float* y;
	std::function<void(Collider* col)> callback;
private:
	Type ColliderType;
	Vector2 position;
	
};

