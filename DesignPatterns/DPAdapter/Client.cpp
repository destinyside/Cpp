#include<iostream>
#include "Target.h"
#include "Adapter.h"
using namespace std;
int main() {
	///////适配器模式
	///////类适配器 Adapter继承Adaptee
	///////对象适配器 Adapter含有Adaptee成员变量
	Target* p = new Adapter;
	p->Request();
	delete p;
	system("pause");
}