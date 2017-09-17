#pragma once
#include "Colleague.h"
class ConcreteColleagueA :
	public Colleague
{
public:
	ConcreteColleagueA(Mediator* mdr);
	~ConcreteColleagueA();
	void Changed();
	void Update();
	void Notify();
};

