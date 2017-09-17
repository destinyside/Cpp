#pragma once
#include "Builder.h"
class ConcreteBuilder :
	public Builder
{
public:
	ConcreteBuilder();
	~ConcreteBuilder();
	void buildPartA(char* a);
	void buildPartB(char* b);
	void buildPartC(char* c);
	char* getResult();
private:
	char* product;
};

