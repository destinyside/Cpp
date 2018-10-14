#include<iostream>
#include "ProductB2.h"


ProductB2::ProductB2()
{
	std::cout << "构造ConcreteFactory2的B类产品" << std::endl;
	std::cout << std::endl;
}


ProductB2::~ProductB2()
{
	std::cout << "析构ConcreteFactory2的B类产品" << std::endl;
	std::cout << std::endl;
}
