#include "Invoker.h"



Invoker::Invoker(Command* cmd):command(cmd)
{
	std::cout << "构造Invoker" << std::endl;
}


Invoker::~Invoker()
{
	delete command;
	std::cout << "析构Invoker" << std::endl;
}

void Invoker::Execute()
{
	std::cout << "Invoker执行Execute" << std::endl;
	command->Execute();
}