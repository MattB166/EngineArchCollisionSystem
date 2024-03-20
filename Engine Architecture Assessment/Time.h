#pragma once
class Time
{
public:
	static Time* instance() { return _instance != nullptr ? _instance : _instance = new Time(); }

private:
	static Time* _instance; 
};

