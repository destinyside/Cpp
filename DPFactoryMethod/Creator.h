#include "Product.h"
#pragma once

class Creator
{
public:
	Product* product;
	Creator();
	virtual ~Creator();
	virtual Product* Create() = 0;
};

