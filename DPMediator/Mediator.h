#pragma once
#include<iostream>
#include "Colleague.h"
using namespace std;
class Mediator
{
public:
	Mediator();
	virtual ~Mediator();
	virtual void ColleagueChanged() = 0;
	virtual void Set(Colleague* A, Colleague* B, Colleague* C) = 0;
};

