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
	//Main loop for prompts of pin generation
	do
	{
		//Prompts
		cout << "\n\t******\\\"Pin Generator v2.0\"/******\n\n"
			<< "\tYou can \"Generate\" and \"E-Mail\" your Pins!" << endl;
		cout << "\n  Select ONE of the Following:\n" << endl;
		for (int i = min_digit; i <= max_digit; i++)//Loop for generating auto output base on min and max digit allowed
			cout << "\t| " << i << "-Digit Pin |" << endl;
		//Inner loop for checking the input validation
		do {
			
			cout << "\n\tYour Choice: ";
			length = _getch() - '0';//Take input and store it as unsigned int by subtracting '0'
			cout << length << endl;
			if (((length < min_digit) || (length > max_digit)))//Check whether the input is in valid range or not
			{
				cout << "\n\t\"INVALID CHOICE!\"" << endl;
				cout << "\t\"Try Again!\"" << endl;
			}
			else 
			{
				break; // Break out of the loop if the input is valid
			}
			} while (true);//Inner loop ends here

		pins[index] = pin_generator(length);//calls the function to generate and store pin in member of Pin class
		cout << "\n\t\t\\Pin = ";//Output generated pin
		cout << "\"" << pins[index] << "\"/" << endl;
		//checks if the maximum capacity has been reached
		//break the loop if max pins are generated
		if ((index + 2) > maximum)
		{
			cout << "\n\t\"Maximum Number of Pins  were Generated!\"" << endl;
			cout << "\t\"Therefore Pin Generation is Terminated!\"" << endl;
			break;
		}
		//Below statement only works if there is capacity available for pin storage
		//prompt to ask if another pin is required
		cout << "\n\tWant another Pin (y/n)? ";
		choice = _getch();
		cout << choice << endl;
		//increment only if the next pin is to be generated
		if (toupper(choice) == 'Y')
		{
			index++;
			system("cls");
		}
	} while (toupper(choice) == 'Y');//Main Loop ends here
	//Pin generation is ended and now the Rest of the code
	if (index > -1)//Makes sure atleast one pin was generated
	{
		//Prompt to ask for showing generated pins during program execution
		cout << "\n\tWant to know the generated pins (y/n)?  ";
		choice = _getch();
		cout << choice << endl;
		//Condition to check whether user wants to know generated pins
		if (toupper(choice) == 'Y')//If condition is true Print the generated pins
		{
			system("cls");
			cout << "\n\tBelow are the Generated Pin(s):" << endl;
			//Call to BubleSort Function only if Pins are to be printed
			bubbleSort(pins, index + 1);
			//Implementation of grouping the generated pins on the basis of length
			//Means all four digit will be under four digit heading and so on
			for (int i = 0; i <= index; i++ )
			{
				if (i == 0 || pins[i].length() != pins[i - 1].length())
					cout << "\n\t" << pins[i].length() << "-Digit" << endl;
				cout << "\t\t" << pins[i] << endl;
			}
			//Prompt to ask for an E-Mail Goes here
			cout << "\n\t\"Want an E-Mail of the Generated Pin(s)!\"" << endl;
			cout << "\n\tYour Choice (y/n): ";
			choice = _getch();
			cout << choice << endl;
			if (toupper(choice) == 'Y')//If condition is true Call to E-Mail
			{
				//Call to E-Mail goes here
			}
		}
	}
}
Pin::~Pin()
{
	//cout << "\nPin Destructor" << endl;
}
