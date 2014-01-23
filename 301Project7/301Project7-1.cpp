/*
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HASH.h"
using namespace std;
void readFile(HASH<6> &h, HASH<6> &h2);
int main()
{
	char entry;
	HASH<6> h;
	HASH<6> h2;


	do{
		//Receive updated data from file on each loop
		readFile(h, h2);
		cout << "-------------- Menu --------------\n"
		 << "a.\tDisplay Hash_1 Table\n"
		 << "b.\tDisplay Hash_2 Table\n"
		 << "c.\tDisplay the balance of a given customer name\n"
		 << "d.\tWithdraw money for a given customer ID\n"
		 << "e.\tClose the account of a given customer ID\n"
		 << "f.\tDeposit money for a given customer name\n"
		 << "g.\tExit\n\n";

	cout << "Enter your choice: ";
	cin >> entry;
	cout << endl;
	if(toupper(entry) =='A')
	{
		cout << "Name\tID\tBalance\n";
		h.Display_Table();
		cout << endl;
	}
	else if(toupper(entry) == 'B')
	{
		cout << "Name\tID\tBalance\n";
		h2.Display_Table();
		cout << endl;
	}
	else if(toupper(entry) == 'C')
	{
		string customer;
		cout << "Enter a customer name: ";
		cin >> customer;
		h.SearchName(customer);
	}
	else if(toupper(entry) == 'D')
	{
		int withdrawID;
		double withdrawAmt;
		cout << "Enter customer ID: ";
		cin >> withdrawID;
		cout << "Enter withdrawal amount: ";
		cin >> withdrawAmt;
		h2.withdraw(withdrawID, withdrawAmt);
		cout << "Updated customer data\n\n";
		cout << "Name\tID\tBalance\n";
		h2.Display_Table();
	}
	else if(toupper(entry)=='E')
	{
		int customerID;
		cout << "Enter account ID to close: ";
		cin >> customerID;
		h2.closeAccount(customerID);
		cout << "Updated customer data\n\n";
		cout << "Name\tID\tBalance\n";
		h2.Display_Table();

	}
	else if(toupper(entry) == 'F')
	{
		double depositAmt;
		string customerName;
		cout << "Enter a customer name: ";
		cin >> customerName;
		cout << "Enter deposit amount: ";
		cin >> depositAmt;
		h.deposit(customerName, depositAmt);
		cout << "Updated customer data\n\n";
		cout << "Name\tID\tBalance\n";
		h.Display_Table();
	}
	}while(toupper(entry)!='G');

	return 0;
}
void readFile(HASH<6> &h, HASH<6> &h2)
{
	//Empty both hashes before inserting data from file
	h.emptyHash();
	h2.emptyHash();
	ifstream readFile;
	readFile.open("data.txt", ios::in);
	string name;
	int	id;
	double balance;
	string line;
	while(getline(readFile, line))
	{
		stringstream linestream(line);
		getline(linestream, name, ' ');
		linestream >> id >> balance;
		h.insert(name,id, balance,1);
		h2.insert(name,id, balance,2);
	}
	readFile.close();
}
*/
