#pragma once
#include<iostream>
using namespace std;
class Handler
{
public:
	Handler();
	virtual ~Handler();
	virtual void HandleRequest(int level) = 0;
};

