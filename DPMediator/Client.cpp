#include<iostream>
#include "Colleague.h"
#include "ConcreteColleagueA.h"
#include "ConcreteColleagueB.h"
#include "ConcreteColleagueC.h"
#include "Mediator.h"
#include "ConcreteMediator.h"
using namespace std;
int main() {
	///////中介者模式
	Mediator* mdr = new ConcreteMediator();
	Colleague* A = new ConcreteColleagueA(mdr);
	Colleague* B = new ConcreteColleagueB(mdr);
	Colleague* C = new ConcreteColleagueC(mdr);
	mdr->Set(A, B, C);
	A->Notify();
	delete mdr;
	system("pause");
}