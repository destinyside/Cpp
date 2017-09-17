#include "Singleton.h"
#include<iostream>
#include<time.h>

Singleton* Singleton::_instance = 0;

Singleton::Singleton()
{
	std::cout << "构造Singleton" << std::endl;
}


Singleton::~Singleton()
{
	std::cout << "析构Singleton" << std::endl;
}

Singleton * Singleton::Instance()
{
	std::cout << "获得Instance" << std::endl;
	if (_instance == 0) {
		_instance = new Singleton;
		time_t t = time(NULL);
		tm* local = new tm;
		localtime_s(local,&t);
		_instance->data = (char*)calloc(64, sizeof(char));
		asctime_s(_instance->data, 64, local);
	}
	return _instance;
}

char * Singleton::getData()
{
	return data;
}
