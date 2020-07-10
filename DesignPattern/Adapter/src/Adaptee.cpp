#include "Adaptee.h"
#include<iostream>


Adaptee::Adaptee()
{
        std::cout << "Adaptee" << std::endl;
}


Adaptee::~Adaptee()
{
        std::cout << "Adaptee" << std::endl;
}

void Adaptee::specificRequest()
{
        std::cout << "AdapteespecificRequest" << std::endl;
}
