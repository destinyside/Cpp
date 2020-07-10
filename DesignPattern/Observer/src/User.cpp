#include "User.h"

User::User(char* name)
{
        uname = name;
         cout << "Cons User " << name <<  endl;
}

User::~User()
{
         cout << "Disc User" << uname <<  endl;
}

void User::update(char* story)
{
         cout << "User " << uname << " get : "<< story <<  endl;
}
