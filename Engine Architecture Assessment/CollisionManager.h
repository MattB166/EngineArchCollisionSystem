#pragma once
#include "Collider.h"
#include <iostream>
#include "BoxCollider.h"
#include "CircleCollider.h"
#include <list>
#include <functional>
#include <map>

/// @brief Static Manager for all Game Object collision
class CollisionManager   
{

public:
	
	/// @brief  Compares two square colliders against each other for collision. If a collision has occured then true is returned.
	/// @param collider1 
	/// @param collider2 
	/// @return 
	static bool SquareCollision(BoxCollider* collider1, BoxCollider* collider2);  

	/// @brief Compares two circle colliders against each other for collision. If a collision occurs then true is returned.
	/// @param collider1 
	/// @param collider2 
	/// @return 
	static bool CircleCollision(CircleCollider* collider1, CircleCollider* collider2);

	/// @brief Compares a circle collider against a box collider for collision. If a collision occurs then true is returned.
	/// @param circ 
	/// @param box 
	/// @return 
	static bool CircleRectCollision(CircleCollider* circ, BoxCollider* box);

	static bool BoundsCollision();  

	/// @brief Iterates through all colliders in the list as pairs. Compares the collider type of nth and n+1 and carries out the relevant collision check between them. 
	static void HandleCollision();
	/// @brief Ticks over the handle collision function 
	static void Update();

	/// @brief Adds a collider object to the Collision Manager collider list. 
	/// @param collider 
	static void AddCollider(Collider* collider);

	/// @brief Removes a collider from the collision list.
	/// @param collider 
	static void RemoveCollider(Collider* collider);

	/// @brief Cleans all the colliders from the list.
	/// @return 
	static void CleanUp(); 

private:
	CollisionManager();
	/// @brief List of the Collision Manager's stored colliders
	static std::list<Collider*> colliders;

	
};

