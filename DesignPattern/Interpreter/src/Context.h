#pragma once
#include<iostream>
using namespace std;
class Context
{
public:
	int exp;
	Context* next;
	Context();
	~Context();
};

