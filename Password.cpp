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
	system("cls");//Clear screen for password working
	   //Variables declarations and initializations
	bool lower_case, upper_case, numbers, s_char;
	index = a;//for setting index to zero every time the call() function is called
	char choice = 0;//For storing choices
	//Main loop for prompts of password generation
	do
	{
		//Initialize all bool variables to false at the start of every loop
		lower_case = upper_case = numbers = s_char = false;
		//Prompts
		cout << "\n\t******\\\"Password Generator v2.0\"/******\n\n"
			<< "\tYou can \"Generate\" and \"E-Mail\" your Passwords!" << endl;
		cout << "\n  Select ONE of the Following:\n" << endl;
		cout << "\t\"a)Quick Generation\"" << endl;
		cout << "\t\"b)Advanced Generation\"" << endl;
		//Inner loop for checking the input validation
		do {
			cout << "\n\tYour Choice (a/b): ";
			choice = _getch();
			cout << choice << endl;
			//Check whether the input is valid or not
			if (toupper(choice) == 'A' || toupper(choice == 'B'))
			{
				break; // Break out of the loop if the input is valid
			}
			else
			{
				cout << "\n\t\"INVALID CHOICE!\"" << endl;
				cout << "\t\"Try Again!\"" << endl;		
			}
		} while (true);//Inner loop ends here
		//Now check statement to select between the above two statements
		switch (choice)
		{
		case 'a':
		{
			cout << "\n\tEnter the Length of Password: ";
			while (!(cin >> length) || (length < 8 || length > 32)) {
				// Check if the input was successful
				if (cin.fail()) 
				{
					// Clear the input buffer to handle the invalid input
					cin.clear();
					//Flushes the input buffeer until '\n' is reached or max input values are removed
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				// Display an error message and prompt the user to enter again
				cout << "\n\t\"Invalid input!\"" << endl;
				cout << "\tPlease enter a value ( 8 to 32) inclusive: ";
			}
			//call to password_generator() to generate and store password
			passwords[index] = password_generator(length, true, true, true, true);
			cout << "\n\t\t\\Password = ";//Output generated password
			cout << "\"" << passwords[index] << "\"/" << endl;	
		}
		break;
		case 'b':
		{}
		}

	} while (toupper(choice) == 'Y');
}

Password::~Password()
{
	//cout << "Password Destructor" << endl;
}
