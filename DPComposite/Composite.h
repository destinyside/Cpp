#pragma once
#include "Component.h"
#include<list>
#include<iostream>
using namespace std;
class Composite :
	public Component
{
public:
	char* cname;
	Composite(char* name);
	~Composite();
	void Operation();
	void Add(Component * c);
	void Remove(Component * c);
	void getChild(int index);
private:

	list<Component*> CList;
};

