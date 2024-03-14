#pragma once
#include <queue> ///class to queue the events 
struct CollisionEvent
{
	//listener
	//event 
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
	void DispatchEvents();
	///might need reference to listeners here too. struct of some sort 
};

