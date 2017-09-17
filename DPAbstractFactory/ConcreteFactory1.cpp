#include<iostream>
#include "ConcreteFactory1.h"
#include "ProductA1.h"
#include "ProductB1.h"

ConcreteFactory1::ConcreteFactory1()
{
	std::cout << "构造ConcreteFactory1" << std::endl;
}

ConcreteFactory1::~ConcreteFactory1()
{
	if (pa != NULL) {
		delete pa;
	}
	if (pb != NULL) {
		delete pb;
	}
	std::cout << "析构ConcreteFactory1" << std::endl;
}

void ConcreteFactory1::createProductA()
{
	std::cout << "创建ConcreteFactory1系列的产品A" << std::endl;
	pa = new ProductA1;
}

void ConcreteFactory1::createProductB()
{
	std::cout << "创建ConcreteFactory1系列的产品B" << std::endl;
	pb = new ProductB1;
}
