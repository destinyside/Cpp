#pragma once
class Singleton
{
public:
	static Singleton* Instance();
	char* getData();
protected:
	Singleton();
	~Singleton();
private:
	static Singleton* _instance;
	char* data;
};

