#include "ConcreteImplementor.h"
#include<iostream>


ConcreteImplementorA::ConcreteImplementorA()
{
	std::cout << "构造ConcreteImplementorA" << std::endl;
}


ConcreteImplementorA::~ConcreteImplementorA()
{
	std::cout << "析构ConcreteImplementorA" << std::endl;
}

void ConcreteImplementorA::OperationImpl() 
{
	std::cout << "执行ConcreteImplementorA的Operation" << std::endl;
}

ConcreteImplementorB::ConcreteImplementorB()
{
	std::cout << "构造ConcreteImplementorB" << std::endl;
}

ConcreteImplementorB::~ConcreteImplementorB()
{
	std::cout << "析构ConcreteImplementorB" << std::endl;
}

void ConcreteImplementorB::OperationImpl()
{
	std::cout << "执行ConcreteImplementorB的Operation" << std::endl;
}