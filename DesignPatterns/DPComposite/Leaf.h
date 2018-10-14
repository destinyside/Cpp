#pragma once
#include "Component.h"
class Leaf :
	public Component
{
public:
	char* lname;
	Leaf(char* name);
	~Leaf();
	void Operation();
};

