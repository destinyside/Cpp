#include "ConcreteCommand.h"



ConcreteCommand::ConcreteCommand(Receiver* rec):receiver(rec)
{
	std::cout << "构造ConcreteCommand" << std::endl;
}


ConcreteCommand::~ConcreteCommand()
{
	delete receiver;
	std::cout << "析构ConcreteCommand" << std::endl;
}

void ConcreteCommand::Execute()
{
	std::cout << "ConcreteCommand执行Execute" << std::endl;
	receiver->Action();
}
