#pragma once
#include "Handler.h"
class ConcreteHandlerA :
	public Handler
{
public:
	ConcreteHandlerA(Handler* next);
	~ConcreteHandlerA();
	void HandleRequest(int level);
private:
	Handler* nextHandler;
};

