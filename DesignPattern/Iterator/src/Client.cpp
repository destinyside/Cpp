#include<iostream>
#include "Iterator.h"
#include "Iterator.cpp"
#include "ConcreteIterator.h"
#include "ConcreteIterator.cpp"
#include "Aggregate.h"
#include "Aggregate.cpp"
#include "ConcreteAggregate.h"
#include "ConcreteAggregate.cpp"

#define T1 int
#define T2 char*

using namespace std;
int main() {
	///////迭代器模式
	Aggregate<T1>* aggr1 = new ConcreteAggregate<T1>;
	aggr1->Push(1);
	aggr1->Push(2);
	aggr1->Push(3);
	aggr1->Push(4);
	aggr1->Push(5);
	Iterator<T1>* iter1 = aggr1->CreateIterator();
	cout << iter1->First() << " get！" << endl;
	while (!iter1->IsEnd()) {
		cout << iter1->Current() << " get！" << endl;
		iter1->Next();
	}
	delete aggr1;
	cout << endl << endl;

	Aggregate<T2>* aggr2 = new ConcreteAggregate<T2>;
        aggr2->Push((char*)"hello");
        aggr2->Push((char*)"ello");
        aggr2->Push((char*)"llo");
        aggr2->Push((char*)"lo");
        aggr2->Push((char*)"o");
	Iterator<T2>* iter2 = aggr2->CreateIterator();
	cout << iter2->First() << " get！" << endl;
	while (!iter2->IsEnd()) {
		cout << iter2->Current() << " get！" << endl;
		iter2->Next();
	}
	delete aggr2;

	system("pause");
}
