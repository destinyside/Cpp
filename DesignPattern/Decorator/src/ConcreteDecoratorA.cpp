#include "ConcreteDecoratorA.h"



ConcreteDecoratorA::ConcreteDecoratorA(DComponent* compo)
{
	comp = compo;
	std::cout << "构造ConcreteDecoratorA" << std::endl;
}


ConcreteDecoratorA::~ConcreteDecoratorA()
{
	std::cout << "析构ConcreteDecoratorA" << std::endl;
}

void ConcreteDecoratorA::Operation()
{
	std::cout << "使用ConcreteDecoratorA进行装饰" << std::endl;
	Decorator::Operation();
	std::cout << "ConcreteDecoratorA装饰了Component" << std::endl;
}
