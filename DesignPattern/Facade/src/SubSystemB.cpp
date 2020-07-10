#include "SubSystemB.h"

SubSystemB::SubSystemB()
{
	std::cout << "构造SubSystemB" << std::endl;
}


SubSystemB::~SubSystemB()
{
	std::cout << "析构SubSystemB" << std::endl;
}

void SubSystemB::MethodB()
{
	std::cout << "执行SubSystemB的MethodB" << std::endl;
}
