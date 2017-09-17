#include<iostream>
#include "AbstractFactory.h"
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"
using namespace std;
int main() {
	///////抽象工厂模式
	AbstractFactory* f;
	f = new ConcreteFactory1;
	f->createProductA();
	f->createProductB();
	delete f;
	f = new ConcreteFactory2;
	f->createProductA();
	f->createProductB();
	delete f;
	system("pause");
}