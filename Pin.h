#pragma once
//Defination for maximum no of pins that can be generated during one execution and stored
#define maximum 2
//how many minimum digits are allowed
#define min_digit 4
//how many max digits are allowed
#define max_digit 7
#include<string>
using namespace std;
class Pin
{
private:
	static unsigned short int index;//static variable to keep track of the number of pins generated
	unsigned short int length = 0;//how many digit pin is required
protected:
	string pins[maximum];//array to store all the generated pins
public:
	Pin();//default constructor
	void call(unsigned short int);//main member function for working during pin prompts
	~Pin();//destructor
};