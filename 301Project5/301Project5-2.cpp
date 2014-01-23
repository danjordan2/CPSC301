//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 5
// File: 301Project5-2.cpp
// ===========================================
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include "Queue.h"
using namespace std;

int main()
{
	float coif;
	int pwr;
	float x;
	char * token;
	char line[80];
	float value = 0;

	cout << "Enter the X value: ";
	cin >> x;
	Queue<float> q;
	cin.ignore();

	cout << "Enter the coefficient and power of the first term: ";
	cin.getline(line, 79);
	token = strtok(line, " ");
	coif = atof(token);
	token=strtok(NULL, " ");
	pwr = atoi(token);
	q.pushq(coif, pwr,x);

	do
	{
		cout << "Enter the coefficient and power of the next term: ";
		cin.getline(line, 79);
		token = strtok(line, " ");
		coif = atof(token);
		token=strtok(NULL, " ");
		pwr = atoi(token);
		q.pushq(coif,pwr,x);
	}while((coif !=0) || (pwr !=0));

	while(!q.Emptyq())
	{

		value+= q.popq();
	}
	cout << "f(" << x << ") = " << value;
	return 0;
}
/*OUTPUT
Enter the X value: 6.3
Enter the coefficient and power of the first term: 5.1 4
Enter the coefficient and power of the next term: 2.3 3
Enter the coefficient and power of the next term: 12.3 1
Enter the coefficient and power of the next term: 8.23 0
Enter the coefficient and power of the next term: 0 0
f(6.3) = 8694.84
 */
