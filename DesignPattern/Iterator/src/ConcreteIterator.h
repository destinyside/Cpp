#pragma once
#include "Iterator.h"
template<typename T>
class ConcreteIterator :
	public Iterator<T>
{
public:
	ConcreteIterator(Aggregate<T>* aggr);
	T First();
	T Next();
	T Current();
	bool IsEnd();
private:
	Aggregate<T>* aggregate;
	int index;
};

