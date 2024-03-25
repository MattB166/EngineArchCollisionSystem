#pragma once
enum Type
{
	SquareCollider,
	CircleCollider
};
class Collider
{
public:

	void SetColliderType(Type type);
	Type GetColliderType();
private:
	Type ColliderType;
};

