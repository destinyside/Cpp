#include "RefinedAbstraction.h"
#include<iostream>


RefinedAbstraction::RefinedAbstraction(Implementor* imp)
{
	impl = imp;
        std::cout << "RefinedAbstraction" << std::endl;
}


RefinedAbstraction::~RefinedAbstraction()
{
	delete impl;
        std::cout << "~RefinedAbstraction" << std::endl;
}

void RefinedAbstraction::Operation()
{
	std::cout << "RefinedAbstraction执行Operation" << std::endl;
	impl->OperationImpl();
}
