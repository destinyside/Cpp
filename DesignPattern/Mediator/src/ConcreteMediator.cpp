#include "ConcreteMediator.h"



ConcreteMediator::ConcreteMediator()
{
	cout << "构造ConcreteMediator" << endl;
}


ConcreteMediator::~ConcreteMediator()
{
	delete colleagueA;
	delete colleagueB;
	delete colleagueC;
	cout << "析构ConcreteMediator" << endl;
}

void ConcreteMediator::ColleagueChanged()
{
	colleagueA->Update();
	colleagueB->Update();
	colleagueC->Update();
}

void ConcreteMediator::Set(Colleague * A, Colleague * B, Colleague * C)
{
	colleagueA = A;
	colleagueB = B;
	colleagueC = C;
}


