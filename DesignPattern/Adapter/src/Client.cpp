#include<iostream>
#include "Target.h"
#include "Adapter.h"
using namespace std;
int main() {
        Target* p = new Adapter;
        p->Request();
        delete p;
        system("pause");
}
