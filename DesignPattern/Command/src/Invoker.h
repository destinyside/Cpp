#pragma once
#include "Command.h"
class Invoker
{
public:
	Invoker(Command* cmd);
	~Invoker();
	void Execute();
private:
	Command* command;
};

