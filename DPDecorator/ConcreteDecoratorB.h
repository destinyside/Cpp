#pragma once
#include "Decorator.h"
class ConcreteDecoratorB :
	public Decorator
{
public:
	ConcreteDecoratorB(DComponent* compo);
	~ConcreteDecoratorB();
	void Operation();
};

