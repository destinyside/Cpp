#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Aggregate;
template<typename T>
class Iterator
{
public:
	Iterator();
	virtual ~Iterator();
	virtual T First() = 0;
	virtual T Next() = 0;
	virtual T Current() = 0;
	virtual bool IsEnd() = 0;
};

