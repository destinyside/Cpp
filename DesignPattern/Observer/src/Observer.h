#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H
#include<iostream>
using std::cout;
using std::endl;

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(char* story) = 0;
private:

};
#endif // !OBSERVER_H


