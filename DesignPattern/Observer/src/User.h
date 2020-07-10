#include "Observer.h"
#pragma once
#ifndef USER_H
#define USER_H
#include<iostream>
using std::cout;
using std::endl;

class User : public Observer
{
public:
	char* uname;
	User(char* name);
	~User();
	void update(char* story);
private:
};
#endif // !USER_H

