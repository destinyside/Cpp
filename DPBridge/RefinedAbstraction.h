#include "Abstraction.h"
#include "Implementor.h"
#include "ConcreteImplementor.h"
#pragma once

class RefinedAbstraction :
	public Abstraction
{
public:
	RefinedAbstraction(Implementor* imp);
	~RefinedAbstraction();
	void Operation();
};

