#include<iostream>
#include<cstdlib>
#include<list>
using namespace std;
class Observer;
class Subject
{
public:
	Subject();
	virtual ~Subject();
	virtual void AddObserver(Observer* o) = 0;
	virtual void RemoveObserver(Observer* o) = 0;
	virtual void Notify(char* story) = 0;
private:

};

Subject::Subject()
{ 
	 cout << "Cons Subject" <<  endl;
}

Subject::~Subject()
{
	 cout << "Disc Subject" <<  endl;
}

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(char* story) = 0;
private:

};

Observer::Observer()
{
	 cout << "Cons Observer" <<  endl;
}

Observer::~Observer()
{
	 cout << "Disc Observer" <<  endl;
}

class User : public Observer
{
public:
	char* uname;
	User(char* name);
	~User();
	void update(char* story);
private:
};

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

class PublicNumber : public Subject
{
public:
	char* pname;
	PublicNumber(char* name);
	~PublicNumber();
	void AddObserver(Observer* o);
	void RemoveObserver(Observer* o);
	void Notify(char* story);
private:
	list<Observer*> OList;
};



PublicNumber::PublicNumber(char* name)
{
	pname = name;
	 cout << "Cons PublicNumber " << name <<  endl;
}
PublicNumber::~PublicNumber()
{
	for(Observer* o : this->OList) 
	{
		delete o;
	}
	 cout << "Disc PublicNumber" <<  endl;
}
void PublicNumber::AddObserver(Observer* o)
{
	this->OList.push_back(o);
}

void PublicNumber::RemoveObserver(Observer* o)
{
	this->OList.remove(o);
}

void PublicNumber::Notify(char* story)
{
	for(Observer* o : this->OList)
	{
		o->update(story);
	}
}


int main() {
	//////Observer Design Pattern
	Observer* o1 = new User("Mike");
	Observer* o2 = new User("Jack");
	Observer* o3 = new User("Tom");
	Observer* o4 = new User("Lily");
	Subject* pn = new PublicNumber("Times");
	pn->AddObserver(o1);
	pn->AddObserver(o2);
	pn->AddObserver(o3);
	pn->AddObserver(o4);
	pn->Notify("Update News");
	delete pn;
	//system("pause");
}





