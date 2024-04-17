#include "EventManager.h"
std::queue<Event*> EventManager::EventQueue;
std::vector<Collider*> EventManager::listeners;
std::map<Collider*, std::function<void(Collider* col,Collider* col1)>> EventManager::listenersFuncMap;
std::map<Collider*,Event> EventManager::listenersTypeMap;

