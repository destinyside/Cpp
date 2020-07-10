#include "ConcreteColleagueC.h"

#include "Mediator.h"


ConcreteColleagueC::ConcreteColleagueC(Mediator* mdr)
{
	mediator = mdr;
	cout << "构造ConcreteColleagueC" << endl;
}


ConcreteColleagueC::~ConcreteColleagueC()
{
	cout << "析构ConcreteColleagueC" << endl;
}

void ConcreteColleagueC::Changed()
{
	Notify();
}

void ConcreteColleagueC::Update()
{
	cout << "ConcreteColleagueC接收到更新请求" << endl;
}

void ConcreteColleagueC::Notify()
{
	cout << "ConcreteColleagueC通知中介者更新" << endl;
	mediator->ColleagueChanged();
}
