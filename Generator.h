//This file contains the functions for generating pin and password
//They return the generated pin or password as string
//Also this file includes functions to implement sorting algorithm to align the output
#pragma once
#include<string>
using namespace std;
//Function to generate and store pin in dynamic memory
string pin_generator(unsigned short int length);
//Function to generate and return password as string
string password_generator(unsigned short int length, bool lower_case, bool upper_case, bool numbers, bool s_char);
//Function to check whether the first string is greater than the second
//Parameters are constant to ensure that the string value is not changed
bool isNumericStringGreater(const string& a, const string& b);
//Bubble sort Algorithm to sort the array of generated pins according to length
//For example the 4-Digit pin will come first and then 5-Digit pin and likewise
void bubbleSort(string arr[], int n);