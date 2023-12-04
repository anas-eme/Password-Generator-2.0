#include "Pin.h"
#include"Generator.h"
#include<iostream>
#include<conio.h>
using namespace std;
unsigned short int Pin::index = 0;//Declares the static variable to zero
Pin::Pin()
{
	length = 0;//Initialize to zero
}
//Defination of call() function
void Pin::call(unsigned short int a)
{
	system("cls");//Clear screen for pin working
	//Variables declarations and initializations
	index = a;//for setting index to zero every time the call() function is called
	char choice;//For storing choices
	//Prompts
	cout << "\n\t******\\\"Pin Generator v2.0\"/******\n\n"
		<< "\tYou can \"Generate\" and \"E-Mail\" your Pin!" << endl;
	//Main loop for prompts of pin generation
	do
	{		
		cout << "\n" << index ;	
		//Inner loop for checking the input validation
		do {
			cout << "\n  Select One of the Following: " << endl;
			for (int i = min_digit; i <= max_digit; i++)//Loop for generating auto output base on min and max digit allowed
				cout << "\t" << i << "-Digit Pin" << endl;
			cout << "\tYour Choice: ";
			length = _getch() - '0';//Take input and store it as unsigned int by subtracting '0'
			cout << length << endl;
			if (((length < min_digit) || (length > max_digit)))//Check whether the input is in valid range or not
			{
				cout << "\n\tINVALID CHOICE!" << endl;
				cout << "\tTry Again!\n" << endl;
			}
			else 
			{
				break; // Break out of the loop if the input is valid
			}
			} while (true);//Inner loop ends here
		pins[index] = pin_generator(length);//calls the function to generate and store pin in member of Pin class
		cout << "\n\t\tPin = ";//Output generated pin
		cout << "\"" << pins[index] << "\"" << endl;
		//checks if the maximum capacity has been reached
		//break the loop if max pins are generated
		if ((index + 2) > maximum)
		{
			cout << "\nMaximum Pins Generated!" << endl;
			cout << "Exiting..." << endl;
			break;
		}
		//prompt to ask if another pin is required
		cout << "\n\tWant another Pin? ";
		choice = _getch();
		cout << choice << endl;
		//increment only if the next pin is to be generated
		if (toupper(choice) == 'Y')
			index++;
	} while (toupper(choice) == 'Y');//Main Loop ends here
	
	if (index > -1)//Makes sure atleast one pin was generated
	{
		//Prompt to ask for showing generated pins during program execution
		cout << "\n\tWant to know the generated pins(y/n)?  ";
		choice = _getch();
		cout << choice << endl;
		//Condition to check whether user wants to know generated pins
		if (toupper(choice) == 'Y')//If condition is true Print the generated pins
		{
			//Call to BubleSort Function if Pins are to be printed
			bubbleSort(pins, index + 1);
			for (int i = 0; i <= index; i++)
				cout << i + 1 << ")" << pins[i] << endl;
		}
	}
}
Pin::~Pin()
{
	//cout << "Destructor is called" << endl;
}
