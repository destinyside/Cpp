#include "Prtotype.h"
#pragma once
class ConcretePrototype :
	public Prototype
{
public:
	ConcretePrototype();
	~ConcretePrototype();
	Prototype* Clone();
};

