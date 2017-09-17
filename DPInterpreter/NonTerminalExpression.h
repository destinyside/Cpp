#pragma once
#include "AbstractExpression.h"
#include "TerminalExpression.h"
class NonTerminalExpression :
	public AbstractExpression
{
public:
	NonTerminalExpression();
	~NonTerminalExpression();
	void Interpret(Context* ctx);
private:
	AbstractExpression* aexp;
};

