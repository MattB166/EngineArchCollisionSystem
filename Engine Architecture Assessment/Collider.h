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
	/// @brief Determines the type of collider this object is.
	/// @param type 
	void SetColliderType(Type type);
	/// @brief Returns the type of this collider.
	/// @return Collider Type
	Type GetColliderType();
	/// @brief Initialises the position of this collider
	/// @param pos 
	void SetPosition(ColliderVector2 pos);
	/// @brief  Returns the Vector2 Position of this collider
	/// @return 
	ColliderVector2 GetPosition();
	/// @brief Flag describing whether collider is checked for collision or not. 
	bool enabled = true;
	float* x;
	float* y;
	/// @brief The callback function attached to this particular collider. 
	std::function<void(Collider* col)> callback;
private:
	/// @brief This struct determines which type of Object/ Collider this is.
	Type ColliderType;
	/// @brief Position of this Collider.
	ColliderVector2 position;
	
};

