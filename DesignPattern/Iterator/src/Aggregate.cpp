#include "Aggregate.h"


template<typename T>
Aggregate<T>::Aggregate()
{
	cout << "构造Aggregate" << endl;
}

template<typename T>
Aggregate<T>::~Aggregate()
{
	cout << "析构Aggregate" << endl;
}
