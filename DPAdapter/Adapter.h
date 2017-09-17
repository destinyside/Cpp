#pragma once
#include "Target.h"
#include "Adaptee.h"
#include<iostream>
class Adapter :
	public Target
{
public:
	Adaptee* p;
	Adapter();
	~Adapter();
	void Request();
};

