#include "Facade.h"



Facade::Facade()
{
	std::cout << "构造Facade" << std::endl;
	A = new SubSystemA;
	B = new SubSystemB;
	C = new SubSystemC;
	D = new SubSystemD;
}


Facade::~Facade()
{
	std::cout << "析构Facade" << std::endl;
	delete A;
	delete B;
	delete C;
	delete D;
}

void Facade::FunctionA()
{
	std::cout << "Facade功能一" << std::endl;
	A->MethodA();
	B->MethodB();
	C->MethodC();
	D->MethodD();
}

void Facade::FunctionB()
{
	std::cout << "Facade功能二" << std::endl;
	D->MethodD();
	C->MethodC();	
	B->MethodB(); 
	A->MethodA();
}
