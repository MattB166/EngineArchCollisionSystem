#pragma once
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
	bool enabled = true;
	float* x;
	float* y;
	std::function<void()> callback;
private:
	Type ColliderType;
	
};

