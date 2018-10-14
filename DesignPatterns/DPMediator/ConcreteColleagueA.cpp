#include "ConcreteColleagueA.h"

#include "Mediator.h"

ConcreteColleagueA::ConcreteColleagueA(Mediator* mdr)
{
	mediator = mdr;
	cout << "构造ConcreteColleagueA" << endl;
}


ConcreteColleagueA::~ConcreteColleagueA()
{
	cout << "析构ConcreteColleagueA" << endl;
}

void ConcreteColleagueA::Changed()
{
	Notify();
}

void ConcreteColleagueA::Update()
{
	cout << "ConcreteColleagueA接收到更新请求" << endl;
}

void ConcreteColleagueA::Notify()
{
	cout << "ConcreteColleagueA通知中介者更新" << endl;
	mediator->ColleagueChanged();
}

