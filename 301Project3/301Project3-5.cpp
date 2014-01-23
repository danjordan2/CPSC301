//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 9
// File: 301Project3-5.cpp
// ===========================================
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "TWO.h"
using namespace std;
int main()
{
	TWO<int, 4> CS131;
	TWO<string, 4> CS121;

	CS131.ReadData("file1.txt");
	cout << "ID \t Balance\n"
		 << "-----------------\n";
	CS131.DisplayData();


	CS121.ReadData("file2.txt");
	cout << "\nID \t Balance\n"
		 << "-----------------\n";
	CS121.DisplayData();



	return 0;
}
/*OUTPUT
ID 	 Balance
-----------------
222  	222.22
33   	333.33
1111 	11.11
444  	 4.40

ID 	 Balance
-----------------
123-45-6666	222.22
456-78-8888	333.33
678-90-0000	11.11
901-23-4444	 4.40
 */
