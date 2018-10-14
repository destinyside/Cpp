#include<iostream>
#include "User.h"
using namespace std;

User::User(char* name)
{
	uname = name;
	std::cout << "构造User ：" << name << std::endl;
}

User::~User()
{
	std::cout << "析构User" << uname << std::endl;
}

void User::update(char* story)
{
	std::cout << "User ：" << uname << " 更新 ： "<< story << std::endl;
}
