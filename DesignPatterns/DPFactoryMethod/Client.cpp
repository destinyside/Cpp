#include<iostream>
#include "Creator.h"
#include "ConcreteCreator.h"
#include "Product.h"
#include "ConcreteProduct.h"
using namespace std;
int main() {
	////// 工厂方法   每一个工厂生产一种产品
	Creator* c = new ConcreteCreator;
	Product* p = c->Create();
	p->ID();
	delete p;
	delete c;
	system("pause");
}