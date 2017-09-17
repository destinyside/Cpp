#include<iostream>
#include<list>
#include "PublicNumber.h"
#include "Observer.h"
#include "PublicNumber.h"



PublicNumber::PublicNumber(char* name)
{
	pname = name;
	std::cout << "¹¹ÔìPublicNumber" << name << std::endl;
}
PublicNumber::~PublicNumber()
{
	for each (Observer* o in this->OList) 
	{
		delete o;
	}
	std::cout << "Îö¹¹PublicNumber" << std::endl;
}
void PublicNumber::AddObserver(Observer* o)
{
	this->OList.push_back(o);
}

void PublicNumber::RemoveObserver(Observer* o)
{
	this->OList.remove(o);
}

void PublicNumber::Notify(char* story)
{
	for each (Observer* o in this->OList)
	{
		o->update(story);
	}
}