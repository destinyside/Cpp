#include "ConcreteProduct.h"
#include<iostream>


ConcreteProduct::ConcreteProduct()
{
	std::cout << "构造ConcreteProduct" << std::endl;
}


ConcreteProduct::~ConcreteProduct()
{
	std::cout << "析构ConcreteProduct" << std::endl;
}

void ConcreteProduct::ID()
{
	std::cout << "这是具体产品！" << std::endl;
}
