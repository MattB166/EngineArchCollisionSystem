#pragma once
#include <iostream> 
class Game
{
public:
	void Run();

private:
	void Update();
	bool isRunning;
	// pointer reference to event manager/handler 
};

