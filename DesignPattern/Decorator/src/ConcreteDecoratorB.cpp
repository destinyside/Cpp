#include "ConcreteDecoratorB.h"




ConcreteDecoratorB::ConcreteDecoratorB(DComponent* compo)
{
	comp = compo;
	std::cout << "构造ConcreteDecoratorB" << std::endl;
}


ConcreteDecoratorB::~ConcreteDecoratorB()
{
	std::cout << "析构ConcreteDecoratorB" << std::endl;
}

void ConcreteDecoratorB::Operation()
{
	std::cout << "使用ConcreteDecoratorB进行装饰" << std::endl;
	Decorator::Operation();
	std::cout << "ConcreteDecoratorB装饰了Component" << std::endl;
}
