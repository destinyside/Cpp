#pragma once
class Prototype
{
public:
	int x;
	int y;
	Prototype();
	virtual ~Prototype();
	virtual Prototype* Clone() = 0;
};

