#pragma once
#include<iostream>
using namespace std;
class PSubject
{
public:
	PSubject();
	virtual ~PSubject();
	virtual void Request() = 0;
};

