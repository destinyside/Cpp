#include<iostream>
#include "Builder.h"
#include "ConcreteBuilder.h"
#include "Director.h"
using namespace std;
int main() {
	///////生成器模式    有其他生成器生成不同部分或不同顺序
	ConcreteBuilder* b = new ConcreteBuilder;
	Director* d = new Director(b);
	d->Construct();
	std::cout << "构造结果：" << b->getResult() << endl;
	delete d;
	delete b;
	system("pause");
}