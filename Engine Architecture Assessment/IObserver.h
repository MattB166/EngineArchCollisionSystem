#pragma once
class IObserver
{

public:
	IObserver();
	virtual void Observe() = 0;
	//virtual void OnCollisionNotify(const GameObject& obj)=0;

private:

};

