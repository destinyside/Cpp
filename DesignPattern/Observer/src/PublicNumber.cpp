#include<iostream>
#include<list>
#include "PublicNumber.h"
#include "Observer.h"
#include "PublicNumber.h"



PublicNumber::PublicNumber(char* name)
{
	pname = name;
	std::cout << "构造PublicNumber" << name << std::endl;
}
PublicNumber::~PublicNumber()
{
	for(Observer* o : this->OList) 
	{
		delete o;
	}
	std::cout << "析构PublicNumber" << std::endl;
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
        for(Observer* o : this->OList)
        {
                o->update(story);
        }
}
