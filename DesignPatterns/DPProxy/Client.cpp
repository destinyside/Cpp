#include<iostream>
#include "PSubject.h"
#include "Proxy.h"
#include "RealSubject.h"
using namespace std;
int main() {
	///////代理模式
	PSubject* s1 = new RealSubject;
	PSubject* s2 = new Proxy(s1);
	s2->Request();
	delete s2;
	system("pause");
}