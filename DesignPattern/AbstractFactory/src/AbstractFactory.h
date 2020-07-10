#pragma once
#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include <iostream>

class AbstractFactory
{
public:
	AbstractFactory();
	virtual ~AbstractFactory();
	virtual void createProductA() = 0;
	virtual void createProductB() = 0;
};
#endif // !ABSTRACTFACTORY_H

