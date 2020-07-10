#include "Receiver.h"



Receiver::Receiver()
{
	std::cout << "构造Receiver" << std::endl;
}


Receiver::~Receiver()
{
	std::cout << "析构Receiver" << std::endl;
}

void Receiver::Action()
{
	std::cout << "Receiver执行Action" << std::endl;
}
