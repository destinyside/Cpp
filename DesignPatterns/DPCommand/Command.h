#pragma once
#include<iostream>
using namespace std;
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void Execute() = 0;
};

