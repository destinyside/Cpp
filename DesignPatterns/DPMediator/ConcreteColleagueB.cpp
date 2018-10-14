#include "ConcreteColleagueB.h"

#include "Mediator.h"


ConcreteColleagueB::ConcreteColleagueB(Mediator* mdr)
{
	mediator = mdr;
	cout << "构造ConcreteColleagueB" << endl;
}


ConcreteColleagueB::~ConcreteColleagueB()
{
	cout << "析构ConcreteColleagueB" << endl;
}

void ConcreteColleagueB::Changed()
{
	Notify();
}

void ConcreteColleagueB::Update()
{
	cout << "ConcreteColleagueB接收到更新请求" << endl;
}

void ConcreteColleagueB::Notify()
{
	cout << "ConcreteColleagueB通知中介者更新" << endl;
	mediator->ColleagueChanged();
}