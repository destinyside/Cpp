#include<iostream>
#include "Invoker.h"
#include "Command.h"
#include "ConcreteCommand.h"
#include "Receiver.h"
using namespace std;
int main() {
	///////命令模式
	Invoker* ivk = new Invoker(new ConcreteCommand(new Receiver));
	ivk->Execute();
	delete ivk;
	system("pause");
}
