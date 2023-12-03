#pragma once
#include<string>
using namespace std;
class Password
{
private:
	static unsigned short int index;
	unsigned short int length;
protected:
	string password[10];
public:
	Password();
	void call();
	~Password();
};