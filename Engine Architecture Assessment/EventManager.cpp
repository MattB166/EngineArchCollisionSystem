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
	
	GameObject* listener1 = listeners.front();
	
	std::cout << "\n\n\n" << std::endl;
	
}

