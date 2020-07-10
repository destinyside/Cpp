#include "SubSystemA.h"



SubSystemA::SubSystemA()
{
	std::cout << "构造SubSystemA" << std::endl;
}


SubSystemA::~SubSystemA()
{
	std::cout << "析构SubSystemA" << std::endl;
}

void SubSystemA::MethodA()
{
	std::cout << "执行SubSystemA的MethodA" << std::endl;
}
