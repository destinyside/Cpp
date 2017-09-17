#include<iostream>
#include "Context.h"
#include "AbstractExpression.h"
#include "TerminalExpression.h"
#include "NonTerminalExpression.h"
using namespace std;
int main() {
	///////解释器模式
	Context* head = NULL;
	Context* p = NULL;
	while (true) {
		p = new Context;
		cout << "请输入符号(0为终结符)：";
		cin >> p->exp;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		}
		else {
			Context* q = head;
			while (q->next != NULL) {
				q = q->next;
			}
			q->next = p;
		}
		if (p->exp == 0) {
			break;
		}
	}
	AbstractExpression* absexp = new NonTerminalExpression;
	absexp->Interpret(head);
	delete absexp;
	system("pause");
}