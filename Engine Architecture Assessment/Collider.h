#pragma once
enum Type
{
	SquareCollider,
	CircleCollider
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
private:
	Type ColliderType;
};

