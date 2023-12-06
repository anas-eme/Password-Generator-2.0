#pragma once
//Defination for maximum no of pins that can be generated during one execution and stored
#define maximum 2
//Defination for minimum length of password
#define min_length 8
//Defination for maximum length of password
//removing t to remove a naming conflict error with standard definations
#define max_lengt 32
#include<string>
using namespace std;
class Password
{
private:
	static unsigned short int index;//static variable to keep track of the number of passwords generated
	unsigned short int length;//what is the length of required password
protected:
	string passwords[maximum];//array to store all the generated passwords
public:
	Password();//default constructor
	void call(unsigned short int a);//main member function for working during password prompts
	void quick_Generation();//member function for quick password generation
	void adv_Generation();//member function for advanced password generation
	~Password();//destructor
};