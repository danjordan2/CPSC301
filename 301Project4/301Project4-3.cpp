/*
//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 4
// File: 301Project4-3.cpp
//=========================================
#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.h"
using namespace std;
int main()
{
	srand ( time(NULL) );
	stack<int, 7> stack;
	stack.ClearStack();
	string phoneNumber;
	char phoneLetter[7];
	int numPosition;
	char readable = 'N';
	cout << "Enter a phone number: ";
	getline(cin, phoneNumber);

	for(int i=6; i<phoneNumber.length(); i++)
	{
		if(isdigit(phoneNumber[i]))
			stack.push(phoneNumber[i]-'0');
	}
	while(toupper(readable)=='N')
	{
	for(int i=0; i<7; i++)
	{
		switch(stack.getElement(i))
		{
			case 2:
			{
				//Randomly select one of 3 letters
				numPosition = (rand() % 3) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 'a';
				else if(numPosition == 2)
					phoneLetter[i] = 'b';
				else if(numPosition == 3)
					phoneLetter[i] = 'c';
				break;
			}
			case 3:
			{
				numPosition = (rand() % 3) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 'd';
				else if(numPosition == 2)
					phoneLetter[i] = 'e';
				else if(numPosition == 3)
					phoneLetter[i] = 'f';
				break;
			}
			case 4:
			{
				numPosition = (rand() % 3) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 'g';
				else if(numPosition == 2)
					phoneLetter[i] = 'h';
				else if(numPosition == 3)
					phoneLetter[i] = 'i';
				break;
			}
			case 5:
			{
				numPosition = (rand() % 3) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 'j';
				else if(numPosition == 2)
					phoneLetter[i] = 'k';
				else if(numPosition == 3)
					phoneLetter[i] = 'l';
				break;
			}
			case 6:
			{
				numPosition = (rand() % 3) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 'm';
				else if(numPosition == 2)
					phoneLetter[i] = 'n';
				else if(numPosition == 3)
					phoneLetter[i] = 'o';
				break;
			}
			case 7:
			{
				numPosition = (rand() % 4) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 'p';
				else if(numPosition == 2)
					phoneLetter[i] = 'q';
				else if(numPosition == 3)
					phoneLetter[i] = 'r';
				else if(numPosition == 4)
					phoneLetter[i] = 's';
				break;
			}
			case 8:
			{
				numPosition = (rand() % 3) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 't';
				else if(numPosition == 2)
					phoneLetter[i] = 'u';
				else if(numPosition == 3)
					phoneLetter[i] = 'v';
				break;
			}
			case 9:
			{
				numPosition = (rand() % 4) + 1;
				if(numPosition == 1)
					phoneLetter[i] = 'w';
				else if(numPosition == 2)
					phoneLetter[i] = 'x';
				else if(numPosition == 3)
					phoneLetter[i] = 'y';
				else if(numPosition == 4)
					phoneLetter[i] = 'z';
				break;
			}
		}
	}
	cout << "1-800-";
	for(int i=0; i<7; i++)
		cout << phoneLetter[i];
	cout << "\nReadable(y/n)?: ";
	cin >> readable;
	}
	cout << "\nHave a nice day";
	return 0;
}
/*
Enter a phone number: 1-800-633-3227
1-800-mdffaas
Readable(y/n)?: n
1-800-ndffbbr
Readable(y/n)?: n
1-800-needcar
Readable(y/n)?: y

Have a nice day
 */
