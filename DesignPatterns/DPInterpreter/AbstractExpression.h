#pragma once
#include<iostream>
#include "Context.h"
using namespace std;
class AbstractExpression
{
public:
	AbstractExpression();
	virtual ~AbstractExpression();
	virtual void Interpret(Context* ctx) = 0;
};

