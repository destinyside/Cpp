#include "RealSubject.h"



RealSubject::RealSubject()
{
	std::cout << "构造RealSubject" << std::endl;
}


RealSubject::~RealSubject()
{
	std::cout << "析构RealSubject" << std::endl;
}

void RealSubject::Request()
{
	std::cout << "RealSubject的Request" << std::endl;
}
