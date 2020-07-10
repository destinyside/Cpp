#include "NonTerminalExpression.h"



NonTerminalExpression::NonTerminalExpression()
{
	cout << "构造NonTerminalExpression" << endl;
}


NonTerminalExpression::~NonTerminalExpression()
{
	delete aexp;
	cout << "析构NonTerminalExpression" << endl;
}


void NonTerminalExpression::Interpret(Context * ctx)
{
	if (ctx != NULL) {
		if (ctx->exp == 0) {
			delete aexp;
			aexp = new TerminalExpression;
			aexp->Interpret(ctx);
		}
		else {
			cout << "非终结符 ： " << ctx->exp << endl;
			if (ctx->next != NULL) {
				delete aexp;
				aexp = new NonTerminalExpression;
				aexp->Interpret(ctx->next);
			}
		}
	}
	else {
		cout << "非正常结束！" << endl;
	}
}
