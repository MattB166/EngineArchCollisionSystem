#pragma once
#include <queue>  
#include <list>
#include <map>
#include <functional>
#include <thread>
#include <mutex>
#include "CollisionManager.h"
enum class EventType
{
	Collision,
	
};
struct Event
{
	EventType type;
	Collider* col1;
	Collider* col2;

	Event(EventType type, Collider* col1, Collider* col2) : type(type), col1(col1), col2(col2) {};
};
template<class T>
class EventManager
{
public: 
	inline static void RegisterListener(T* listener, std::function<void(Collider* col, Collider* col2)> func, EventType type)
	{
		listeners.push_back(listener);
		listenerTypeMap.insert(std::make_pair(listener, type));
		listenerFuncMap.insert(std::make_pair(listener, func));
		//std::cout << "Listener Registered" << std::endl;
	}
	inline static void ProduceEvent(EventType type, Collider* col, Collider* col2)
	{
		Event* event = new Event(type, col, col2);
		//std::lock_guard<std::mutex> lock(mutex);
		EventQueue.push(event);
		//std::cout << "Event added to queue" << std::endl;
		
	}
	
	inline static void Update()
	{
		//mutex.lock();	
		DispatchEvents();
		//mutex.unlock();
	}
	/*static void UpdateCollisionSystem();*/
private:
	EventManager();
	//std::queue<CollisionEvent> EventQueue;
	
	inline static void DispatchEvents()
	{
		//std::cout << " Running Dispatch Events" << std::endl;
		//std::lock_guard<std::mutex> lock(mutex);
		
		if (!EventQueue.empty())         /////doesnt get into this loop
		{
			std::cout << "Dispatching Event" << std::endl;
			
			Event* event = EventQueue.front(); ///checks through queue for events, then checks through the listeners to see if they care about the event. if so, call the callback function.
			EventQueue.pop();
			for (auto it = listeners.begin(); it != listeners.end(); ++it)
			{
				if (listenerTypeMap[*it] == event->type)
				{
					std::cout << "Event Dispatched" << std::endl;
					listenerFuncMap[*it](event->col1, event->col2);
					
				}
			}
		}
		
		

	}

	
	static std::list<T*> listeners;  
	static std::map<T*, std::function<void(Collider* col, Collider* col2)>> listenerFuncMap;
	static std::map<T*, EventType> listenerTypeMap;
	static std::queue<Event*> EventQueue;
	static std::mutex mutex;

};

template<class T>
std::list<T*> EventManager<T>::listeners;
template<class T>
std::map<T*, std::function<void(Collider* col, Collider* col2)>> EventManager<T>::listenerFuncMap;
template<class T>
std::map<T*, EventType> EventManager<T>::listenerTypeMap;
template<class T>
std::queue<Event*> EventManager<T>::EventQueue;
template<class T>
std::mutex EventManager<T>::mutex;