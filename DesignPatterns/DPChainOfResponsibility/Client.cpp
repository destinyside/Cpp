#include<iostream>
#include "Handler.h"
#include "ConcreteHandlerA.h"
#include "ConcreteHandlerB.h"
#include "ConcreteHandlerC.h"
using namespace std;
int main() {
	///////职责链模式
	Handler* C = new ConcreteHandlerC(NULL);
	Handler* B = new ConcreteHandlerB(C);
	Handler* A = new ConcreteHandlerA(B);
	A->HandleRequest(5);
	A->HandleRequest(50);
	A->HandleRequest(500);
	A->HandleRequest(5000);
	delete A;
	system("pause");
}