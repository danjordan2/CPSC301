//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 6
// File: 301Project6-3.cpp
//=========================================
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include "queuepk.h"
#include "stackpk.h"
using namespace std;
int main()
{

	queuepk<char> q;
	stackpk<char> s;
	char queueChar;
	char stackChar;
	bool isPalindrome;
	string line;
	char restart = 'Y';
	while(toupper(restart) == 'Y')
	{
	cout << "Enter a sentence: ";
	getline(cin, line);
	for(int i=0; i<line.length(); i++)
	{
		if(isalnum(line[i]))
		{
			q.pushq(toupper(line[i]));
			s.pushs(toupper(line[i]));
		}
	}
	while(!q.Emptyq() && !s.Emptys())
	{
		queueChar = q.popq();
		stackChar = s.pops();
		if(queueChar == stackChar)
			isPalindrome = true;
		else
		{
			isPalindrome = false;
			break;
		}
	}
	if(isPalindrome == true)
		cout << "It is a palindrome" << endl;
	else
		cout << "It is not a palindrome" << endl;
	cout << "Continue(y/n)?: ";
	cin >> restart;
	cin.ignore();
	}

	return 0;
}
/*OUTPUT
Enter a sentence: A Toyota race fast ..safe car a Toyota
It is a palindrome
Continue(y/n)?: y
Enter a sentence: THAT'S ALL
It is not a palindrome
Continue(y/n)?: n
 */
