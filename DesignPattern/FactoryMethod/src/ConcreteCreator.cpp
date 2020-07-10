#include "ConcreteCreator.h"
#include "ConcreteProduct.h"
#include<iostream>


ConcreteCreator::ConcreteCreator()
{
	std::cout << "构造ConcreteCreator" << std::endl;
}


ConcreteCreator::~ConcreteCreator()
{
	std::cout << "析构ConcreteCreator" << std::endl;
}

Product * ConcreteCreator::Create()
{
	return new ConcreteProduct;
}
