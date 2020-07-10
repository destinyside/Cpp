#pragma once
#include<iostream>
using namespace std;
#include "SubSystemA.h"
#include "SubSystemB.h"
#include "SubSystemC.h"
#include "SubSystemD.h"
class Facade
{
public:
	Facade();
	~Facade();
	void FunctionA();
	void FunctionB();
private:
	SubSystemA* A;
	SubSystemB* B;
	SubSystemC* C;
	SubSystemD* D;
};

