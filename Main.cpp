#include<iostream>
#include<cstdlib>//for srand()
#include<ctime>//for time()
#include<conio.h>//for getch()
#include"Pin.h"
#include"Password.h"
using namespace std;
int main()
{
	time_t now = 0;//Variable for storing time variable
	srand(time(NULL));	//Sets the seed value to srand() function
	char choice = 0;

	//Here Main Application Loop goes
	do
	{
		//Object instanciation every time the loop is run
		//This means a fresh instance every time the loop is run again
		Pin pin;
		Password password;
		choice = 0;//reinitialize for a fresh start for every iteration	
		cout << "\n\t\"Application Version v2.0\"" << endl;
		cout << "\n\tWhat do you want to DO?\n\n"
			<< "\t\ta) Generate Pin\n"
			<< "\t\tb) Generate Password\n\n"
			<< "\t\tYour Choice (a/b): ";
		choice = _getch();
		cout << choice << endl;
		
		switch (choice)	//Statement to check the choice made by user
		{
		case 'a':
		case 'A':
			pin.call(0);//call to member function of pin for input, genration and output
			break;
		case 'b':
		case 'B':
			password.call(0);//call to member function of pin for input, genration and output
			break;
		default:
			cout << "\t\tINVALID CHOICE\n" << endl;
			break;
		}
		cout << "\n\tDo you Want to run Application Again (y/n)? ";//Prompt to run the program again
		choice = _getch();
		cout << choice << endl;
			system("cls");//Clear screen for restart of application
	} while (toupper(choice) == 'Y');
	now = clock();
	for (; clock() - now < (0.2 * CLOCKS_PER_SEC););//Time delay of 0.2s
	cout << "\n\tApplication Ended Successfully"
		<< "\n\tThank You!" << (char)2 << " For using our service\n\t";
	system("pause");//Stops the console at the end of program
	return 0;
}