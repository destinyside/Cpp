#include "Leaf.h"
#include<iostream>


Leaf::Leaf(char* name)
{
	lname = name;
	std::cout << "构造Composite ： " << name << std::endl;
}


Leaf::~Leaf()
{
	std::cout << "析构Composite ： " << lname << std::endl;
}

void Leaf::Operation()
{
	std::cout << "Leaf ： " << lname << " 的Operation" << std::endl;
}
