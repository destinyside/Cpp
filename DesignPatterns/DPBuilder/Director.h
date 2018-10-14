#pragma once
#include "Builder.h"
class Director
{
public:
	Director(Builder* builder);
	~Director();
	void Construct();
private:
	Builder* builder;
};

