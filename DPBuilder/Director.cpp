#include<iostream>
#include "Builder.h"
#include "Director.h"

Director::Director(Builder* bdr)
{
	builder = bdr;
	std::cout << "构造Director" << std::endl;
}

Director::~Director()
{
	std::cout << "析构Director" << std::endl;
}

void Director::Construct()
{
	builder->buildPartA("测试");
	builder->buildPartB("一下");
	builder->buildPartC("生成器");
	std::cout << "构造完成！" << std::endl;
}
