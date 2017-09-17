#pragma once
#include "Colleague.h"
class ConcreteColleagueC :
	public Colleague
{
public:
	ConcreteColleagueC(Mediator* mdr);
	~ConcreteColleagueC();
	void Changed();
	void Update();
	void Notify();

};

