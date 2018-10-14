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
	virtual void Update() = 0;//////收到中介者更新
	virtual void Notify() = 0;//////主动更新
protected:
	Mediator* mediator;
};

