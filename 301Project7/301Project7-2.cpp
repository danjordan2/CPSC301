#include <iostream>
#include <cstring>
#include <cstdlib>
#include "HASH-2.h"
using namespace std;
int main()
{
	char * token;
	char line[80];
	int data;
	HASH<5> h;
	HASH<5> h2;
	HASH<5> h3;
	cout << "Enter 5 integers: ";
	cin.getline(line, 25);
	token = strtok(line, " ");
	cout << "Data: ";
	while(token!=NULL)
	{
		cout << token << " ";
		h.push(atoi(token),1);
		token=strtok(NULL, " ");
	}

	cout << "\nAfter 1st insertion: ";
	for(int i=0; i<5; i++)
	{
		while(!h.Emptyq(i))
		{
			int data = h.popq(i);
			cout << data << " ";
			h2.push(data,2);
		}
	}
	cout << "\nAfter 2nd insertion: ";
	for(int i=0; i<5; i++)
	{
		while(!h2.Emptyq(i))
		{
			int data = h2.popq(i);
			cout << data << " ";
			h3.push(data,3);
		}
	}
	cout << "\nAfter 3rd insertion: ";
	for(int i=0; i<5; i++)
	{
		while(!h3.Emptyq(i))
		{
			int data = h3.popq(i);
			cout << data << " ";
		}
	}

	return 0;
}
//1 1 3 2 1
