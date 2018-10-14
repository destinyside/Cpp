#pragma once
#include "Handler.h"
class ConcreteHandlerB :
	public Handler
{
public:
	ConcreteHandlerB(Handler* next);
	~ConcreteHandlerB();
	void HandleRequest(int level);
private:
	Handler* nextHandler;
};

