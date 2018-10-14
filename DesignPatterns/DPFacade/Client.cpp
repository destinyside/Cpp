#include<iostream>
#include "Facade.h"
using namespace std;
int main() {
	///////外观模式
	Facade* f = new Facade;
	f->FunctionA();
	f->FunctionB();
	delete f;
	system("pause");
}