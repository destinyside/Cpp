#include<iostream>
#include "ProductA1.h"



ProductA1::ProductA1()
{
	std::cout << "构造ConcreteFactory1的A类产品" << std::endl;
	std::cout << std::endl;
}


ProductA1::~ProductA1()
{
	std::cout << "析构ConcreteFactory1的A类产品" << std::endl;
	std::cout << std::endl;
}
