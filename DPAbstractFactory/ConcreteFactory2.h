#pragma once
#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"
#ifndef CONCRETEFACTORY2_H
#define CONCRETEFACTORY2_H

class ConcreteFactory2 :
	public AbstractFactory
{
public:
	AbstractProductA* pa;
	AbstractProductB* pb;
	ConcreteFactory2();
  ~ConcreteFactory2();
  void createProductA();
  void createProductB();
};

#endif
