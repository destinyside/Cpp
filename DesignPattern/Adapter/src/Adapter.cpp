#include "Adapter.h"


Adapter::Adapter()
{
        std::cout << "Adapter" << std::endl;
        p = new Adaptee;
}


Adapter::~Adapter()
{
        delete p;
        std::cout << "Adapter" << std::endl;
}


void Adapter::Request()
{
        std::cout << "AdapterRequest" << std::endl;
        p->specificRequest();
}
