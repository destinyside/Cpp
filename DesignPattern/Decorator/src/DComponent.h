#pragma once
#include<iostream>
using namespace std;
class DComponent
{
public:
	DComponent();
	virtual ~DComponent();
	virtual void Operation() = 0;
};

