#include "ConcreteHandlerC.h"



ConcreteHandlerC::ConcreteHandlerC(Handler* next) :nextHandler(next)
{
	std::cout << "构造ConcreteHandlerC" << std::endl;
}


ConcreteHandlerC::~ConcreteHandlerC()
{
	delete nextHandler;
	std::cout << "析构ConcreteHandlerC" << std::endl;
}

void ConcreteHandlerC::HandleRequest(int level)
{
	if (level < 1000) {
		std::cout << "ConcreteHandlerC可以处理请求，处理中。。。" << std::endl;
	}
	else if (nextHandler == NULL) {
		std::cout << "ConcreteHandlerC不可以处理请求，且无下一处理者，放弃处理！" << std::endl;
	}
	else {
		std::cout << "ConcreteHandlerC不可以处理请求，转给下一个处理者。" << std::endl;
		nextHandler->HandleRequest(level);
	}
}
