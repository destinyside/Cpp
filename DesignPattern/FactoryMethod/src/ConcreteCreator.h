#pragma once
#include "Creator.h"
class ConcreteCreator :
	public Creator
{
public:
	ConcreteCreator();
	~ConcreteCreator();
	Product* Create();
};

