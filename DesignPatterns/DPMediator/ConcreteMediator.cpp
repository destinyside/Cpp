#include "ConcreteMediator.h"



ConcreteMediator::ConcreteMediator()
{
	cout << "¹¹ÔìConcreteMediator" << endl;
}


ConcreteMediator::~ConcreteMediator()
{
	delete colleagueA;
	delete colleagueB;
	delete colleagueC;
	cout << "Îö¹¹ConcreteMediator" << endl;
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


