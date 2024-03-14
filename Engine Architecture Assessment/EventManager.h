#pragma once
#include "GameObject.h"
#include <queue> ///class to queue the events 
#include <list>
struct CollisionEvent ///might actually be needed in collision manager instead of this 
{
	//listener
	//event 
	///which objects collided 
};
class EventManager
{
public: 
	static EventManager* instance() { return _instance != nullptr ? _instance : _instance = new EventManager(); } ///might not need to be an instance
   //as each object might need its own event manager 

private:
	static EventManager* _instance;
	///hold a queue of events 
	/// maybe something like? 
	std::queue<CollisionEvent> EventQueue;
	///also need a list of registered listeners 
	void AddEvent(CollisionEvent event);
	void DispatchEvents();
	///might need reference to listeners here too. struct of some sort 
	//like this?
	std::list<GameObject> listeners;
	
};

	