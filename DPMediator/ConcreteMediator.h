#pragma once
#include "Mediator.h"

class ConcreteMediator :
	public Mediator
{
public:
	ConcreteMediator();
	~ConcreteMediator();
	void ColleagueChanged();
	void Set(Colleague * A, Colleague * B, Colleague * C);
private:
	Colleague* colleagueA;
	Colleague* colleagueB;
	Colleague* colleagueC;
};

