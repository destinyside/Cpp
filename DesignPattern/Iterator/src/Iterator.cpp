#include "Iterator.h"


template<typename T>
Iterator<T>::Iterator()
{
	cout << "构造Iterator" << endl;
}

template<typename T>
Iterator<T>::~Iterator()
{
	cout << "析构Iterator" << endl;
}
