#pragma once
#include <iostream>
#include "SDL.h"
class Time
{
public:
	Time();
	static Time* instance() { return _instance != nullptr ? _instance : _instance = new Time(); }
	float SetTimeScale(float scale);
	float GetDeltaTime()const;
	float UpdateDeltaTime();
private:
	static Time* _instance; 
	float deltaTime;
	float timeScale;
	Uint32 previousFrameTicks;
	
};

