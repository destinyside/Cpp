#include "Colleague.h"

#include "Mediator.h"

Colleague::Colleague()
{
	cout << "构造Colleague" << endl;
}


Colleague::~Colleague()
{
	cout << "析构Colleague" << endl;
}

void Colleague::Notify()
{
	Changed();
}
