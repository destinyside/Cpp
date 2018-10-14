#pragma once

class Implementor
{
public:
	Implementor();
	~Implementor();
	virtual void OperationImpl() = 0;
};

