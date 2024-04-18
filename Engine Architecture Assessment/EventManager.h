#pragma once
#include <queue>  
#include <list>
#include <map>
#include <functional>
#include "Collider.h"
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

	Event() : type(EventType::Collision), col1(nullptr), col2(nullptr) {};
	Event(EventType type, Collider* col1, Collider* col2) : type(type), col1(col1), col2(col2) {};
};
class EventManager
{
public: 
	inline static void RegisterListener(Collider* col, std::function<void(Collider* col1, Collider* col2)> callback, EventType type)
	{
		listeners.push_back(col);
		listenersFuncMap.insert(std::make_pair(col, callback));
		listenersTypeMap.insert(std::make_pair(col, Event(type, nullptr, nullptr)));
	}

	inline static void ProduceEvent(EventType type, Collider* col1, Collider* col2)
	{
		Event* event = new Event(type, col1, col2);
		EventQueue.push(event);

	}

	inline static void Update()
	{
		while (!EventQueue.empty())
		{
			std::cout << "Producing event\n" << std::endl; 
			Event* event = EventQueue.front();
			EventQueue.pop();
			for (auto& listener : listeners)
			{
				if (listenersTypeMap[listener].type == event->type)
				{
					listenersFuncMap[listener](event->col1, event->col2);
				}
			}
		}
	}

	static void CleanUp()
	{
		listeners.clear();
		listenersFuncMap.clear();
		listenersTypeMap.clear();
		while (!EventQueue.empty())
		{
			Event* event = EventQueue.front();
			EventQueue.pop();
			delete event;
		}
	}
private:
	EventManager();
	static std::vector<Collider*> listeners;
	static std::queue<Event*> EventQueue;
	static std::map<Collider*, std::function<void(Collider* col1, Collider* col2)>> listenersFuncMap;
	static std::map<Collider*, Event> listenersTypeMap;

	
	
	
};

