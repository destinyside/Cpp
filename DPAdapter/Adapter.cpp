#include "Adapter.h"


Adapter::Adapter()
{
	std::cout << "构造Adapter" << std::endl;
	p = new Adaptee;
}


Adapter::~Adapter()
{
	delete p;
	std::cout << "析构Adapter" << std::endl;
}


void Adapter::Request()
{
	std::cout << "这是Adapter的Request方法" << std::endl;
	p->specificRequest();
}
