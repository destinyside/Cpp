#pragma once
#include<iostream>

using namespace std;
class Mediator;
class Colleague
{
public:
	Colleague();
	virtual ~Colleague();
	virtual void Changed() = 0;
        virtual void Update() = 0;
        virtual void Notify() = 0;
protected:
	Mediator* mediator;
};

