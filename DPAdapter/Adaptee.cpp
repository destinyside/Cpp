#include "Adaptee.h"
#include<iostream>


Adaptee::Adaptee()
{
	std::cout << "构造Adaptee" << std::endl;
}


Adaptee::~Adaptee()
{
	std::cout << "析构Adaptee" << std::endl;
}

void Adaptee::specificRequest()
{
	std::cout << "这是Adaptee的specificRequest方法" << std::endl;
}
