#pragma once
#include "Implementor.h"
class ConcreteImplementorA : public Implementor
{
public:
	ConcreteImplementorA();
	~ConcreteImplementorA();
	void OperationImpl();
};

class ConcreteImplementorB : public Implementor
{
public:
	ConcreteImplementorB();
	~ConcreteImplementorB();
	void OperationImpl();
};