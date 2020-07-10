#include<iostream>
#include "Prtotype.h"
#include "ConcretePrototype.h"
using namespace std;
int main() {
	///////原型模式
	Prototype* p = new ConcretePrototype;
	p->x = 123;
	p->y = 456;
	cout << "值：x " << p->x << " y " << p->y << endl;
	p = p->Clone();
	cout << "值：x " << p->x << " y " << p->y << endl;
	delete p;
	system("pause");
}
