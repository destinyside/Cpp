#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(char* story) = 0;
private:

};
#endif // !OBSERVER_H


