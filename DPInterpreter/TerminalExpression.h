#pragma once
#include "AbstractExpression.h"
class TerminalExpression :
	public AbstractExpression
{
public:
	TerminalExpression();
	~TerminalExpression();
	void Interpret(Context* ctx);
};

