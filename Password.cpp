#include "Password.h"
#include"Generator.h"
#include<iostream>
#include<conio.h>
using namespace std;
unsigned short int Password::index = 0;//Declares the static variable to zero
Password::Password()
{
	length = 0;//Initialize to zero
}
//Defination of call() function
void Password::call(unsigned short int a)
{
}

Password::~Password()
{
	//cout << "Password Destructor" << endl;
}
