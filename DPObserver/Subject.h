#include "Observer.h"
#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

class Subject
{
public:
	Subject();
	virtual ~Subject();
	virtual void AddObserver(Observer* o) = 0;
	virtual void RemoveObserver(Observer* o) = 0;
	virtual void Notify(char* story) = 0;
private:

};


#endif // !SUBJECT_H
