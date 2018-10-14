#include "Component.h"
#include<iostream>


Component::Component()
{
	std::cout << "¹¹ÔìComponent" << std::endl;
}


Component::~Component()
{
	std::cout << "Îö¹¹Component" << std::endl;
}

void Component::Add(Component * c)
{
}

void Component::Remove(Component * c)
{
}

void Component::getChild(int index)
{
}

