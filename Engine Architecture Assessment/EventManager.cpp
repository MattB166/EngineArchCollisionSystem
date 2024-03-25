#include "EventManager.h"
EventManager* EventManager::_instance = nullptr;

void EventManager::RegisterListener(GameObject* listener)
{
	listeners.push_back(listener);
	std::cout << "Added: " << listener->getName() << " to listeners list" << std::endl; 
	if (listener->GetType() == ShapeSquare)
	{
		//CollisionManager::instance()->CreateCollider(listener->GetInformation()->x, listener->GetInformation()->y, listener->GetInformation()->w, listener->GetInformation()->h);
	}
	else if (listener->GetType() == ShapeCircle)
	{
		//CollisionManager::instance()->CreateCollider(listener->GetInformation()->x, listener->GetInformation()->y, listener->GetInformation()->w, listener->GetInformation()->h);
	}
	
}

void EventManager::UpdateCollisionSystem()
{
	//CollisionManager::instance()->UpdatePositions();
	GameObject* listener1 = listeners.front();
	/*std::cout << "First listener X position is: " << listener1->GetPosition().x << std::endl;
	std::cout << "First listener Y position is: " << listener1->GetPosition().y << std::endl;
	std::cout << "First Listener collider pos is :" << listener1->GetInformation()->x << ", " << listener1->GetInformation()->y << std::endl;*/
	std::cout << "\n\n\n" << std::endl;
	
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
