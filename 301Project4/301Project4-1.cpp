/*
//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 4
// File: 301Project4-1.cpp
//=========================================
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;
const int STACK_SIZE = 100;
int main()
{
	bool isPalindrome;
	string sentence;
	stack<char, STACK_SIZE> s;
	stack<char, STACK_SIZE> s2;
	s.ClearStack();
	s2.ClearStack();
	char restart = 'Y';
	while(toupper(restart) == 'Y')
	{
		cout << "Enter a sentence: ";
		getline(cin, sentence);
		//Reads string into stack
		for(int i=sentence.length(); i>=0; i--)
		{
			if(isalpha(sentence[i]))
				s.push(tolower(sentence[i]));
		}
		//Reads backwards string into another stack
		for(int i=0; i<sentence.length(); i++)
		{
			if(isalpha(sentence[i]))
				s2.push(tolower(sentence[i]));
		}
		while(!s.isEmpty())
		{
			if(s.pop() == s2.pop())
				isPalindrome = true;
			else
				isPalindrome = false;
		}
		if(isPalindrome == true)
			cout << "It's a palindrome" << endl;
		else
			cout << "It's not a palindrome" << endl;
		cout << "CONTINUE?(y/n): ";
		cin >> restart;
		cin.ignore();
	}
	return 0;

/*OUTPUT
Enter a sentence: is this a palindrome?
It's not a palindrome
CONTINUE?(y/n): y
Enter a sentence: A Toyota! Race face..safe car: a Toyota
It's a palindrome
CONTINUE?(y/n): n
*/
