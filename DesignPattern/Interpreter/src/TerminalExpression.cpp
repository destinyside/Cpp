#include "TerminalExpression.h"



TerminalExpression::TerminalExpression()
{
	cout << "构造TerminalExpression" << endl;
}


TerminalExpression::~TerminalExpression()
{
	cout << "析构TerminalExpression" << endl;
}

void TerminalExpression::Interpret(Context * ctx)
{
	cout << "终结符 ： " << ctx->exp << endl;
}
