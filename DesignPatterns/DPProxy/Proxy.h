#pragma once
#include "PSubject.h"
#include "RealSubject.h"
#include<iostream>
using namespace std;
class Proxy :
	public PSubject
{
public:
	Proxy(PSubject* sub);
	~Proxy();
	void Request();
	void before();
	void after();
private:
	PSubject* rs;
};

