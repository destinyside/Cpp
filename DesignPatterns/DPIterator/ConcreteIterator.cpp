#include "ConcreteIterator.h"
#include "Aggregate.h"

template<typename T>
ConcreteIterator<T>::ConcreteIterator(Aggregate<T>* agret):aggregate(agret)
{
	index = 0;
	cout << "¹¹ÔìConcreteIterator" << endl;
}

template<typename T>
T ConcreteIterator<T>::First()
{
	index = 0;
	return aggregate->Pop(0);
}

template<typename T>
T ConcreteIterator<T>::Next()
{
	index++;
	if (index < aggregate->Count()) {
		return aggregate->Pop(index);
	}
	else {
		return NULL;
	}
}

template<typename T>
T ConcreteIterator<T>::Current()
{
	return aggregate->Pop(index);
}

template<typename T>
bool ConcreteIterator<T>::IsEnd()
{
	return index >= aggregate->Count() ? true : false;
}
