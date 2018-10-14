#include "Proxy.h"


Proxy::Proxy(PSubject* sub)
{
	rs = sub;
	std::cout << "构造Proxy" << std::endl;
}


Proxy::~Proxy()
{
	delete rs;
	std::cout << "析构Proxy" << std::endl;
}

void Proxy::Request()
{
	before();
	std::cout << "Proxy向RealRequest请求" << std::endl;
	rs->Request();
	after();
}

void Proxy::before()
{
	std::cout << "Proxy执行before" << std::endl;
}

void Proxy::after()
{
	std::cout << "Proxy执行after" << std::endl;
}
