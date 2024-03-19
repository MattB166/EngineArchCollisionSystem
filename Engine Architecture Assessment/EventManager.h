#pragma once
#include "GameObject.h"
#include <queue> ///class to queue the events 
#include <list>
class GameObject;
class EventManager
{
public: 
	static EventManager* instance() { return _instance != nullptr ? _instance : _instance = new EventManager(); } ///might not need to be an instance
   //as each object might need its own event manager 
	void RegisterListener(GameObject* listener);
private:
	static EventManager* _instance;
	
	//std::queue<CollisionEvent> EventQueue;
	
	//void AddEvent(CollisionEvent event);
	//void DispatchEvents();
	
	std::list<GameObject*> listeners;
	
};

	