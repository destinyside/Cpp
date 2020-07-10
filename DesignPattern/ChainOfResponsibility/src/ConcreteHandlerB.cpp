#include "ConcreteHandlerB.h"




ConcreteHandlerB::ConcreteHandlerB(Handler* next) :nextHandler(next)
{
	std::cout << "构造ConcreteHandlerB" << std::endl;
}


ConcreteHandlerB::~ConcreteHandlerB()
{
	delete nextHandler;
	std::cout << "析构ConcreteHandlerB" << std::endl;
}

void ConcreteHandlerB::HandleRequest(int level)
{
	if (level < 100) {
		std::cout << "ConcreteHandlerB可以处理请求，处理中。。。" << std::endl;
	}
	else if (nextHandler == NULL) {
		std::cout << "ConcreteHandlerB不可以处理请求，且无下一处理者，放弃处理！" << std::endl;
	}
	else {
		std::cout << "ConcreteHandlerB不可以处理请求，转给下一个处理者。" << std::endl;
		nextHandler->HandleRequest(level);
	}
}
