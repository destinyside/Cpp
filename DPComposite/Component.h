#pragma once
class Component
{
public:
	Component();
	virtual ~Component();
	virtual void Operation() = 0;
	virtual void Add(Component* c);
	virtual void Remove(Component* c);
	virtual void getChild(int index);
};

