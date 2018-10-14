#pragma once
#include "Decorator.h"
class ConcreteDecoratorA :
	public Decorator
{
public:
	ConcreteDecoratorA(DComponent* compo);
	~ConcreteDecoratorA();
	void Operation();
};

