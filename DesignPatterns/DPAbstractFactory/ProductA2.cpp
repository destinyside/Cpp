#include<iostream>
#include "ProductA2.h"


ProductA2::ProductA2()
{
	std::cout << "构造ConcreteFactory2的A类产品" << std::endl;
	std::cout << std::endl;
}


ProductA2::~ProductA2()
{
	std::cout << "析构ConcreteFactory2的A类产品" << std::endl;
	std::cout << std::endl;
}
