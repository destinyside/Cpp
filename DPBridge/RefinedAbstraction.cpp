#include "RefinedAbstraction.h"
#include<iostream>


RefinedAbstraction::RefinedAbstraction(Implementor* imp)
{
	impl = imp;
	std::cout << "构造RefinedAbstraction" << std::endl;
}


RefinedAbstraction::~RefinedAbstraction()
{
	delete impl;
	std::cout << "析构RefinedAbstraction" << std::endl;
}

void RefinedAbstraction::Operation()
{
	std::cout << "RefinedAbstraction执行Operation" << std::endl;
	impl->OperationImpl();
}