#include "Colleague.h"

#include "Mediator.h"

Colleague::Colleague()
{
	cout << "¹¹ÔìColleague" << endl;
}


Colleague::~Colleague()
{
	cout << "Îö¹¹Colleague" << endl;
}

void Colleague::Notify()
{
	Changed();
}
