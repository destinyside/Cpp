#include "Decorator.h"



Decorator::Decorator()
{
	std::cout << "构造Decorator" << std::endl;
}


Decorator::~Decorator()
{
	delete comp;
	std::cout << "析构Decorator" << std::endl;
}

void Decorator::Operation()
{
	std::cout << "Decorator执行Component的Operation" << std::endl;
	comp->Operation();
}
