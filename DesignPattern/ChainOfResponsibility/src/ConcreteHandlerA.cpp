#include "ConcreteHandlerA.h"


ConcreteHandlerA::ConcreteHandlerA(Handler* next):nextHandler(next)
{
	std::cout << "构造ConcreteHandlerA" << std::endl;
}


ConcreteHandlerA::~ConcreteHandlerA()
{
	delete nextHandler;
	std::cout << "析构ConcreteHandlerA" << std::endl;
}

void ConcreteHandlerA::HandleRequest(int level)
{
	std::cout << "处理请求，等级 ： " << level << std::endl;
	if (level < 10) {
		std::cout << "ConcreteHandlerA可以处理请求，处理中。。。" << std::endl;
	}
	else if (nextHandler == NULL) {
		std::cout << "ConcreteHandlerA不可以处理请求，且无下一处理者，放弃处理！" << std::endl;
	}
	else {
		std::cout << "ConcreteHandlerA不可以处理请求，转给下一个处理者。" << std::endl;
		nextHandler->HandleRequest(level);
	}
}
