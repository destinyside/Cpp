#pragma once
#include "Command.h"
#include "Receiver.h"
class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver* rec);
	~ConcreteCommand();
	void Execute();
private:
	Receiver* receiver;
};

