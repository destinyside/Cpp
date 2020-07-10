#include "ConcreteComponent.h"



ConcreteComponent::ConcreteComponent()
{
	std::cout << "构造ConcreteComponent" << std::endl;
}


ConcreteComponent::~ConcreteComponent()
{
	std::cout << "析构ConcreteComponent" << std::endl;
}

void ConcreteComponent::Operation()
{
	std::cout << "ConcreteComponent的Operation" << std::endl;
}
