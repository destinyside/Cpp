#pragma once
#include "DComponent.h"
class ConcreteComponent :
	public DComponent
{
public:
	ConcreteComponent();
	~ConcreteComponent();
	void Operation();
};

