#pragma once
#include <queue>  
#include <list>
#include <map>
#include <functional>
#include "Collider.h"
#include "CollisionManager.h"
/// @brief Enum of the type of event which can be generated.
enum class EventType
{
	Collision,
	
};
/// @brief Struct of an event type enum and colliders which make up an event item. 
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
	/// @brief Registers an Object's collider as a listener for an event. 
	/// @param col 
	/// @param callback 
	/// @param type 
	inline static void RegisterListener(Collider* col, std::function<void(Collider* col1, Collider* col2)> callback, EventType type)
	{
		listeners.push_back(col);
		listenersFuncMap.insert(std::make_pair(col, callback));
		listenersTypeMap.insert(std::make_pair(col, Event(type, nullptr, nullptr)));
	}
	/// @brief Removes a listener from the Event Manager.
	/// @param col 
	inline static void UnRegisterListener(Collider* col)
	{
		listeners.erase(std::remove(listeners.begin(), listeners.end(), col), listeners.end());
		listenersFuncMap.erase(col);
		listenersTypeMap.erase(col);
	}

	/// @brief Generates an event of given type and informs listeners to this event. 
	/// @param type 
	/// @param col1 
	/// @param col2 
	inline static void ProduceEvent(EventType type, Collider* col1, Collider* col2)
	{
		Event* event = new Event(type, col1, col2);
		EventQueue.push(event);

	}
	/// @brief Ticks through event queue every frame to process events.
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
	/// @brief Removes all listeners and events from Event Manager. 
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
	/// @brief The list of collider listeners.
	static std::vector<Collider*> listeners;
	/// @brief A queue of type 'Event' which stores the generated events.
	static std::queue<Event*> EventQueue;
	/// @brief Map which stores listeners and their respective callback function. 
	static std::map<Collider*, std::function<void(Collider* col1, Collider* col2)>> listenersFuncMap;
	/// @brief Map which stores listeners and the type of event they are registered to.
	static std::map<Collider*, Event> listenersTypeMap;

	
	
	
};

