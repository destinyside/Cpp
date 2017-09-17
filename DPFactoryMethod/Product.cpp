#include "Product.h"
#include<iostream>


Product::Product()
{
	std::cout << "构造Product" << std::endl;
}


Product::~Product()
{
	std::cout << "析构Product" << std::endl;
}

void Product::ID()
{
	std::cout << "这是抽象产品！" << std::endl;
}
