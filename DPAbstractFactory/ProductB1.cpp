#include<iostream>
#include "ProductB1.h"

ProductB1::ProductB1()
{
	std::cout << "构造ConcreteFactory1的B类产品" << std::endl;
	std::cout << std::endl;
}


ProductB1::~ProductB1()
{
	std::cout << "析构ConcreteFactory1的B类产品" << std::endl;
	std::cout << std::endl;
}
