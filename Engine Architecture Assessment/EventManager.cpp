#include "EventManager.h"
EventManager* EventManager::_instance = nullptr;

void EventManager::RegisterListener(GameObject* listener)
{
	listeners.push_back(listener);
	std::cout << "Added: " << listener->getName() << " to listeners list" << std::endl; 
}

//void EventManager::AddEvent(CollisionEvent event)
//{
//	EventQueue.push(event);
//}
//
//void EventManager::DispatchEvents()
//{
//	while (!EventQueue.empty())
//	{
//		EventQueue.pop(); 
//	}
//}
