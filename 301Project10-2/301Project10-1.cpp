//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 10
// File: 301Project10-1.cpp
// ===========================================
#include <iostream>
#include <cstring>
#include <time.h>
#include "Queue.h"
const int MAX_ITEMS = 15;
using namespace std;
int main()
{
	srand(time(NULL));
	Queue<int> A, B, C;
	int listA;
	int listB;
	int loop=0;
	int temp;
	bool duplicate = false;
	for(int i=0; i<MAX_ITEMS; i++)
		A.pushq(rand()%100+1);
	
	cout << "This is the original list: ";
	while(!A.Emptyq())
	{
		listA = A.popq();
		cout << listA << " ";
		B.pushq(listA);
	}
	cout << endl << endl;
		int n=0;
	while(!B.Emptyq())
	{

		//Odd numbers
		while(n==0 && !B.Emptyq())
		{
			listB = B.popq();

			//If even number, push it back onto the queue and restart loop
			if(listB %2 == n)
			{
				B.pushq(listB);
				loop++;
				if(loop == B.getCount())
					//Breaks endless loop if all remaining numbers are odd
					n=1;

			}
			else
			{
				//Otherwise, push odd number onto even/odd queue		
					C.pushq(listB);
					loop=0;
					n=0; //break odd number loop
			}
		}
		//Even numbers
		while(n==1 && !B.Emptyq())
		{
			listB = B.popq();


			//If odd number, push it back onto the queue and restart loop
			if(listB %2==n)
			{
				B.pushq(listB);
				loop++;
				if(loop == B.getCount())
					//Breaks endless loop if all remaining numbers are odd
					n=0;

			}
			else
			{
				//Otherwise, push even number onto even/odd queue
					C.pushq(listB);
					loop=0;
					n=0; //break even number loop
			}
		}
	}
	int count = C.getCount();
	cout << "This is the new list: ";
	while(!C.Emptyq())
		cout << C.popq() << " ";
	cout << endl;

return 0;
}
/*OUTPUT
This is the original list: 82 23 78 40 13 50 90 39 59 42 68 87 21 1 69

This is the new list: 23 78 13 50 39 42 87 82 59 68 21 40 1 90 69
Press any key to continue . . .
 */
