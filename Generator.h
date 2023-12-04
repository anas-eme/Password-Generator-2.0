//This file contains the functions for generating pin and password
//These functions take arguments of memory address which is dynamically allocated for storage
//These functions return nothing as they are directly accessing the memory
#pragma once
#include<cstdlib>	//For rand() function
using namespace std;
//Function to generate and store pin in dynamic memory
string pin_generator(unsigned short int length) 
{
	char* pin = new char[length + 1];//Creats dynamic memory for the storage of the generated pin
	for (int i = 0; i < length; i++)//Main loop to generate and store random pin
		pin[i] = 48 + rand() % 10;//rand() function generates random numbers
	pin[length] = '\0';//Ensure the char memory is terminated properly
	string generatedPin(pin); // Convert the char array to a string
	delete[] pin; // Free the allocated memory
	return generatedPin;//Returns Generated Pin
}

//Function to generate and store password in dynamic memory
//It takes address of the dynamically allocated memory
string password_generator(unsigned short int length, bool lower_case, bool upper_case, bool numbers, bool s_char)
{
	unsigned short int i = 0, no = 0;
	bool ch_chosen = false;//This variable is to check whether a char was chosen or not during inner loop
	char* password = new char[length + 1];
	//Password Generation Goes here
	do {
		//Make the variable to false at start of every loop of generating a single char of password
		ch_chosen = false;
		do
		{
			no = 1 + rand() % 4;	//Generates a random number to pick from the below list 
			switch (no)				//which should be included in the password
			{
			case 1:		//Case for lower case alphabets
				if (lower_case)
				{
					password[i] = 97 + rand() % 26;
					ch_chosen = true;
				}
				break;
			case 2:		//Case for Upper case alphabets
				if (upper_case)
				{
					password[i] = 65 + rand() % 26;
					ch_chosen = true;
				}
				break;
			case 3:		//Case for Numbers from 0 to 9
				if (numbers)

				{
					password[i] = 48 + rand() % 10;
					ch_chosen = true;
				}
				break;
			case 4:		//Case for set of Special characters
				if (s_char)
				{
					no = 1 + rand() % 2;
					if (no == 1)
						password[i] = 58 + rand() % 7;
					if (no == 2)
						password[i] = 35 + rand() % 4;
					ch_chosen = true;
				}
				break;
			}
		} while (!ch_chosen);//checks whether one of the choice was made based on user prefrences
		i++;
	} while (i < length);//Loop ends after successful password generation
	password[length] = '\0';///Ensure the char memory is terminated properly
	string generatedPassword(password);// Convert the char array to a string
	delete[] password;	// Free the allocated memory
	return generatedPassword;//Returns generated Password
}
//Bubble sort Algorithm to sort the array of generated pins according to length
//For example the 4-Digit pin will come first and then 5-Digit pin and likewise
void bubbleSort(string arr[], int n)
{
	for (int i = 0; i < n - 1; ++i) //Makes passes through the array
	{
		for (int j = 0; j < n - i - 1; ++j) //Makes checking of elements for each pass
		{
			// Compare adjacent strings using the isNumericStringGreater function
			//If first string is greater swap the string
			if (isNumericStringGreater(arr[j], arr[j + 1])) 
			{
				swap(arr[j], arr[j + 1]);//Function for swaping adjacent strings
			}
		}
	}
}
//Function to check whether the first string is greater than the second so that in bubble sort 
//Parameters are constant to ensure that the string value is not changed
bool isNumericStringGreater(const string& a, const string& b) 
{
	//condition to check whether the length of first element is equal to the second
	//so return that the first is smaller than the second to return false
	//this will skip the swap function as there is no need for swaping as both are equal in length
	if (a.length() != b.length()) 
	{
		//if they are unequal true will be returned to execute swap function
		return a.length() > b.length();
	}
	return a < b;//returns a false statement to skip execution of swap function
}