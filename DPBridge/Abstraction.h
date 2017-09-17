#include "Implementor.h"
#pragma once

class Abstraction
{
public:
	Abstraction();
	virtual ~Abstraction();
	virtual void Operation() = 0;
	Implementor* impl;
};

