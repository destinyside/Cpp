#pragma once
#include "Colleague.h"
class ConcreteColleagueB :
	public Colleague
{
public:
	ConcreteColleagueB(Mediator* mdr);
	~ConcreteColleagueB();
	void Changed();
	void Update();
	void Notify();
};

