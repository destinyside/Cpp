#include<iostream>
#include "DComponent.h"
#include "Decorator.h"
#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"
using namespace std;
int main() {
	///////装饰模式
	DComponent* comp = new ConcreteComponent;
	Decorator* deco = new ConcreteDecoratorB(comp);
	deco->Operation();
	delete deco;
	system("pause");
}
