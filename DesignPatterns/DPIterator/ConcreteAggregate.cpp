#include "ConcreteAggregate.h"


template<typename T>
ConcreteAggregate<T>::ConcreteAggregate():iterator(NULL)
{
	items.clear();
	cout << "¹¹ÔìConcreteAggregate" << endl;
}

template<typename T>
ConcreteAggregate<T>::~ConcreteAggregate()
{
	if (iterator != NULL) {
		delete iterator;
		iterator = NULL;
	}
	cout << "Îö¹¹ConcreteAggregate" << endl;
}

template<typename T>
Iterator<T>* ConcreteAggregate<T>::CreateIterator()
{
	if (iterator == NULL) {
		iterator = new ConcreteIterator<T>(this);
	}
	return iterator;
}

template<typename T>
void ConcreteAggregate<T>::Push(T item)
{
	items.push_back(item);
}

template<typename T>
T ConcreteAggregate<T>::Pop(int index)
{
	return items[index];
}

template<typename T>
int ConcreteAggregate<T>::Count()
{
	return items.size();
}
