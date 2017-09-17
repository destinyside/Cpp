#pragma once
class Builder
{
public:
	Builder();
	virtual ~Builder();
	virtual void buildPartA(char* a) = 0;
	virtual void buildPartB(char* b) = 0;
	virtual void buildPartC(char* c) = 0;
};

