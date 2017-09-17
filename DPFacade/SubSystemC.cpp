#include "SubSystemC.h"



SubSystemC::SubSystemC()
{
	std::cout << "构造SubSystemC" << std::endl;
}


SubSystemC::~SubSystemC()
{
	std::cout << "析构SubSystemC" << std::endl;
}

void SubSystemC::MethodC()
{
	std::cout << "执行SubSystemC的MethodC" << std::endl;
}
