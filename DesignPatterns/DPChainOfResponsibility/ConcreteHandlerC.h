#pragma once
#include "Handler.h"
class ConcreteHandlerC :
	public Handler
{
public:
	ConcreteHandlerC(Handler* next);
	~ConcreteHandlerC();
	void HandleRequest(int level);
private:
	Handler* nextHandler;
};

