//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 5
// File: 301Project5-1.cpp
// ===========================================
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Sets.h"
using namespace std;
int main()
{
	Sets<int> A, B, AUB, AIB;

	char * token;
	char setA[80];
	char setB[80];

	cout << "Enter the elements of set A: ";
	cin.getline(setA, 79);
	token = strtok(setA, " ");
	while(token!=NULL)
	{
		A.Insert(atoi(token));
		token=strtok(NULL, " ");
	}
	cout << "Enter the elements of set B: ";
	cin.getline(setB, 79);
	token = strtok(setB, " ");
	while(token!=NULL)
	{
		B.Insert(atoi(token));
		token=strtok(NULL, " ");
	}

	AIB.Inter(A,B);
	AUB.Union(A,B);

	cout << "Set A = ";
	A.display();

	cout << "Set B = ";
	B.display();

	cout << "A Intersect B = ";
	AIB.display();
	cout << "A Union B = ";
	AUB.display();
	return 0;
}
/*OUTPUT
Enter the elements of set A: 5 3 4 2 1
Enter the elements of set B: 7 9 8 1 6
Set A = { 1  2  3  4  5 }
Set B = { 1  6  7  8  9 }
A Intersect B = { 1 }
A Union B = { 1  2  3  4  5  6  7  8  9 }
 */
