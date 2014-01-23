//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 6
// File: 301Project6-2.cpp
// ===========================================
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include "queuepk-2.h"
using namespace std;
int main()
{
	float coif;
	int pwr;
	float x;
	char * token;
	char line[80];
	float value = 0;
	float value2 = 0;
	cout << "Enter the X value: ";
	cin >> x;
	queuepk <float> q;
	queuepk <float> q2;
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
		if((coif !=0) || (pwr !=0))
			q.pushq(coif,pwr,x);
	}while((coif !=0) || (pwr !=0));
	cout << "Now enter the terms of the second polynomial\n"
		 << "Enter the coefficient and power of the first term: ";
	cin.getline(line, 79);
	token = strtok(line, " ");
	coif = atof(token);
	token=strtok(NULL, " ");
	pwr = atoi(token);
	q2.pushq(coif, pwr,x);
	do
	{
		cout << "Enter the coefficient and power of the next term: ";
		cin.getline(line, 79);
		token = strtok(line, " ");
		coif = atof(token);
		token=strtok(NULL, " ");
		pwr = atoi(token);
		if((coif !=0) || (pwr !=0))
			q2.pushq(coif,pwr,x);
	}while((coif !=0) || (pwr !=0));

	cout << "F(X) = ";
	while(!q.Emptyq())
	{
		value+= q.popq();
		if(!q.Emptyq())
			cout << " + ";
	}
	cout<< "\nG(X) = ";
	while(!q2.Emptyq())
	{
		value2+= q2.popq();
		if(!q2.Emptyq())
			cout << " + ";
	}
	cout << "\nf(" << x << ") = " << value
	     << "\ng(" << x << ") = " << value2
	     << "\nf(" << x << ") + g(" << x << ") = " << value+value2;
	return 0;
}
/*OUTPUT
Enter the X value: 3
Enter the coefficient and power of the first term: 5 4
Enter the coefficient and power of the next term: 3 2
Enter the coefficient and power of the next term: 5 1
Enter the coefficient and power of the next term: 0 0
Now enter the terms of the second polynomial
Enter the coefficient and power of the first term: 4 3
Enter the coefficient and power of the next term: 5 2
Enter the coefficient and power of the next term: 0 0
F(X) = 5X^4 + 3X^2 + 5X^1
G(X) = 4X^3 + 5X^2
f(3) = 447
g(3) = 153
f(3) + g(3) = 600
 */
