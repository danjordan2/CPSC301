//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 9
// File: 301Project9-3.cpp
// ===========================================
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "BST-2.h"
using namespace std;
int main()
{
	srand(time(0));
	BST<int> p;
	for(int i=0; i<50; i++)
		p.Insert(rand()%50);


	p.DispTree();

	cout << endl;
	return 0;
}
/*OUTPUT
Number: 1, Frequency: 3
Number: 2, Frequency: 3
Number: 4, Frequency: 2
Number: 7, Frequency: 1
Number: 9, Frequency: 2
Number: 10, Frequency: 2
Number: 11, Frequency: 1
Number: 16, Frequency: 1
Number: 19, Frequency: 1
Number: 20, Frequency: 3
Number: 21, Frequency: 1
Number: 23, Frequency: 1
Number: 24, Frequency: 1
Number: 27, Frequency: 2
Number: 28, Frequency: 1
Number: 29, Frequency: 1
Number: 30, Frequency: 5
Number: 31, Frequency: 1
Number: 32, Frequency: 1
Number: 33, Frequency: 1
Number: 37, Frequency: 3
Number: 39, Frequency: 1
Number: 40, Frequency: 1
Number: 41, Frequency: 1
Number: 42, Frequency: 1
Number: 43, Frequency: 3
Number: 44, Frequency: 1
Number: 45, Frequency: 2
Number: 47, Frequency: 1
Number: 49, Frequency: 2
 */
