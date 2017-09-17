#pragma once
#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"
#ifndef CONCRETEFACTORY1_H
#define CONCRETEFACTORY1_H

class ConcreteFactory1 : public AbstractFactory
{
public:
	AbstractProductA* pa;
	AbstractProductB* pb;
	ConcreteFactory1();
	~ConcreteFactory1();
	void createProductA();
	void createProductB();
};

#endif // !CONCRETEFACTORY_H
