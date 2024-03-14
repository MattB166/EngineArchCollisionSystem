#include "EventManager.h"

void EventManager::AddEvent(CollisionEvent event)
{
	EventQueue.push(event);
}

void EventManager::DispatchEvents()
{
	while (!EventQueue.empty())
	{
		EventQueue.pop(); 
	}
}
