#include<iostream>
#include "Singleton.h"
using namespace std;
int main() {
	///////单例模式
	Singleton* p = Singleton::Instance();
	std::cout << "单例数据1 ：" << p->getData() << std::endl;
	p = Singleton::Instance();
	std::cout << "单例数据2 ：" << p->getData() << std::endl;
	system("pause");
}