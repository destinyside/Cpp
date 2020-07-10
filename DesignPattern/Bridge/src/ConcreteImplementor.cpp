#include "ConcreteImplementor.h"
#include<iostream>


ConcreteImplementorA::ConcreteImplementorA()
{
        std::cout << "ConcreteImplementorA" << std::endl;
}


ConcreteImplementorA::~ConcreteImplementorA()
{
        std::cout << "~ConcreteImplementorA" << std::endl;
}

void ConcreteImplementorA::OperationImpl() 
{
        std::cout << "ConcreteImplementorA Operation" << std::endl;
}

ConcreteImplementorB::ConcreteImplementorB()
{
        std::cout << "ConcreteImplementorB" << std::endl;
}

ConcreteImplementorB::~ConcreteImplementorB()
{
        std::cout << "~ConcreteImplementorB" << std::endl;
}

void ConcreteImplementorB::OperationImpl()
{
        std::cout << "ConcreteImplementorB Operation" << std::endl;
}
