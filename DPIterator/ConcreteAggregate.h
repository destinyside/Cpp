#pragma once
#include "Aggregate.h"
#include "ConcreteIterator.h"
#include<vector>
template<typename T>
class ConcreteAggregate : public Aggregate<T>
{
public:
	ConcreteAggregate();
	~ConcreteAggregate();
	Iterator<T>* CreateIterator();
	void Push(T item);
	T Pop(int index);
	int Count();
private:
	Iterator<T>* iterator;
	vector<T> items;
};

