#include "Subject.h"
#include "Observer.h"
#include<list>
#pragma once
#ifndef PUBLICNUMBER_H
#define PUBLICNUMBER_H
using namespace std;

class PublicNumber : public Subject
{
public:
	char* pname;
	PublicNumber(char* name);
	~PublicNumber();
	void AddObserver(Observer* o);
	void RemoveObserver(Observer* o);
	void Notify(char* story);
private:
	list<Observer*> OList;
};
#endif // !PUBLICNUMBER_H

