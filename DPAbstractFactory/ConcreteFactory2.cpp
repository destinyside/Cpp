#include<iostream>
#include "ConcreteFactory2.h"
#include "ProductA2.h"
#include "ProductB2.h"


ConcreteFactory2::ConcreteFactory2()
{
	std::cout << "构造ConcreteFactory2" << std::endl;
}

ConcreteFactory2::~ConcreteFactory2()
{
	if (pa != NULL) {
		delete pa;
	}
	if (pb != NULL) {
		delete pb;
	}
	std::cout << "析构ConcreteFactory2" << std::endl;
}

void ConcreteFactory2::createProductA()
{
	std::cout << "创建ConcreteFactory2系列的产品A" << std::endl;
	pa = new ProductA2;
}

void ConcreteFactory2::createProductB()
{
	std::cout << "创建ConcreteFactory2系列的产品B" << std::endl;
	pb = new ProductB2;
}
