#pragma once
#include<iostream>
#include "Iterator.h"
using namespace std;
template<typename T>
class Aggregate
{
public:
	Aggregate();
	virtual ~Aggregate();
	virtual Iterator<T>* CreateIterator() = 0;
	virtual void Push(T item) = 0;
	virtual T Pop(int index) = 0;
	virtual int Count() = 0;
};

