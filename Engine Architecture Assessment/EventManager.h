#pragma once
#include "GameObject.h"
#include <queue>  
#include <list>
#include "CollisionManager.h"
class GameObject;
class EventManager
{
public: 
	static EventManager* instance() { return _instance != nullptr ? _instance : _instance = new EventManager(); } 
	void RegisterListener(GameObject* listener);
	void UpdateCollisionSystem();
private:
	static EventManager* _instance;
	
	//std::queue<CollisionEvent> EventQueue;
	
	//void AddEvent(CollisionEvent event);
	//void DispatchEvents();
	
	std::list<GameObject*> listeners;  //need to constantly be telling the collision system the new positions of the listeners 
	
};

	