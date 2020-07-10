#include<iostream>
#include<cstdlib>
#include "Observer.h"
#include "PublicNumber.h"
#include "Subject.h"
#include "User.h"
using namespace std;
int main() {
        ///////观察者模式
        Observer* o1 = new User((char*)"张三");
        Observer* o2 = new User((char*)"李四");
        Observer* o3 = new User((char*)"王五");
        Observer* o4 = new User((char*)"赵六");
        Subject* pn = new PublicNumber((char*)"故事会");
        pn->AddObserver(o1);
        pn->AddObserver(o2);
        pn->AddObserver(o3);
        pn->AddObserver(o4);
        pn->Notify((char*)"从前有一个强迫症患。。。");
        delete pn;
        system("pause");
}
