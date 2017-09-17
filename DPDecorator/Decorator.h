#pragma once
#include "DComponent.h"
class Decorator :
	public DComponent
{
public:
	DComponent* comp;
	Decorator();
	virtual ~Decorator();
	void Operation();
};

