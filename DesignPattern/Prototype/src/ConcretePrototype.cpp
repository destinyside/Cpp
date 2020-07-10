#include "ConcretePrototype.h"
#include<iostream>


ConcretePrototype::ConcretePrototype()
{
	std::cout << "构造ConcretePrototype" << std::endl;
}


ConcretePrototype::~ConcretePrototype()
{
	std::cout << "析构ConcretePrototype" << std::endl;
}

Prototype * ConcretePrototype::Clone()
{
	std::cout << "克隆ConcretePrototype" << std::endl;
	Prototype* p = new ConcretePrototype;
	p->x = this->x;
	p->y = this->y;
	return p;
}
