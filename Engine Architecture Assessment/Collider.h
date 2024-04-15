#pragma once
#include <functional>
struct ColliderVector2
{
	float x, y;
};
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
	void SetPosition(ColliderVector2 pos);
	ColliderVector2 GetPosition();
	bool enabled = true;
	float* x;
	float* y;
	std::function<void(Collider* col)> callback;
private:
	Type ColliderType;
	ColliderVector2 position;
	
};

