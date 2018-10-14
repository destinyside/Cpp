#include "ConcreteCreator.h"
#include "ConcreteProduct.h"
#include<iostream>


ConcreteCreator::ConcreteCreator()
{
	std::cout << "¹¹ÔìConcreteCreator" << std::endl;
}


ConcreteCreator::~ConcreteCreator()
{
	std::cout << "Îö¹¹ConcreteCreator" << std::endl;
}

Product * ConcreteCreator::Create()
{
	return new ConcreteProduct;
}
