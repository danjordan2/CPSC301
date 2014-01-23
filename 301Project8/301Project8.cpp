//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 8
// File: 301Project8.cpp
//=========================================
#include <iostream>
#include <string>

#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

struct RECORD{
	int ID;
	char * LAST_NAME;
	char * FIRST_NAME;
	double BALANCE;
};
void InitializaFile();
void Search(int ID);
void DisplayFile();
void Deposit(int ID);
void Withdraw(int ID);
void CloseAccount(int ID);
void WriteTextFile();
void DisplayMenu();
char * StrToCharPtr(string str);
const int MAX_ITEMS = 55;
//====== main() =============================================
int main()
{
	int selection; int id;
    InitializaFile();
	do
	{
		DisplayMenu();
		cout << "\nEnter your selection: ";
		cin >> selection;
		switch(selection)
		{
			case 1: cout << endl; DisplayFile(); break;
			case 2: cout << "Enter ID to search: "; cin >> id; cout << endl; Search(id); break;
			case 3:	cout << "Enter account ID: "; cin >> id; Deposit(id); cout << endl; DisplayFile(); break;
			case 4: cout << "Enter account ID: "; cin >> id; Withdraw(id); cout << endl; DisplayFile(); break;
			case 5: cout << "Enter account ID: "; cin >> id; CloseAccount(id); DisplayFile(); break;
			case 6:	WriteTextFile(); exit(1); break;
		}
		cout << endl;
	}while(selection!=6);

	return 0;
}
//==============================================================

//====== Deposit() =============================================
void Deposit(int ID)
{
	double amount;
	RECORD st; fstream fbin;
	fbin.open("file.raf", ios::in| ios::out |ios::binary);
	fbin.seekg((ID/10-1)*sizeof(st),ios::beg);
	int pos = fbin.tellg();
	fbin.read((char*)&st, sizeof(st));
	cout << "Enter deposit amount: ";
	cin >> amount;
	st.BALANCE += amount;
	fbin.seekp(pos,ios::beg);
	fbin.write((char*)&st, sizeof(st));
	fbin.close();
}
//==============================================================

//====== Withdraw() ============================================
void Withdraw(int ID)
{
	double amount;
	RECORD st; fstream fbin;
	fbin.open("file.raf", ios::in| ios::out |ios::binary);
	fbin.seekg((ID/10-1)*sizeof(st),ios::beg);
	int pos = fbin.tellg();
	fbin.read((char*)&st, sizeof(st));
	cout << "Enter withdrawal amount: ";
	cin >> amount;
	st.BALANCE -= amount;
	fbin.seekp(pos,ios::beg);
	fbin.write((char*)&st, sizeof(st));
	fbin.close();
}
//==============================================================

//====== CloseAccount() ========================================
void CloseAccount(int ID)
{
	RECORD st; fstream fbin;
	fbin.open("file.raf", ios::in| ios::out |ios::binary);
	fbin.seekg((ID/10-1)*sizeof(st),ios::beg);
	int pos = fbin.tellg();
	fbin.read((char*)&st, sizeof(st));
	st.ID=0; st.LAST_NAME="bbbb"; st.FIRST_NAME="bbbb"; st.BALANCE = 0.0;
	fbin.seekp(pos,ios::beg);
	fbin.write((char*)&st, sizeof(st));
	fbin.close();
}
//==============================================================

//====== DisplayFile() =========================================
void DisplayFile()
{
	RECORD st; fstream fbin;
	fbin.open("file.raf", ios::in|ios::binary);
	cout << "These are the contents of the file\n";
	fbin.read((char*)&st, sizeof(st));
	while(true)
	{
		if(st.ID != 0 && st.BALANCE != 0)
			cout << st.ID << "\t" << st.LAST_NAME << "," << st.FIRST_NAME << "\t" << st.BALANCE << endl;
		fbin.read((char*)&st, sizeof(st));
		if(fbin.fail()) break;
	}
	fbin.close();
}
//==============================================================

//====== Search() ==============================================
void Search(int ID)
{
		RECORD st; fstream fbin;
		fbin.open("file.raf", ios::in|ios::binary);
		cout << "These are the contents of the search\n";
		int pos = (ID/10-1)*sizeof(st);
		fbin.seekg(pos,ios::beg);
		fbin.read((char*)&st, sizeof(st));
		cout << st.ID << "\t" << st.LAST_NAME << "," << st.FIRST_NAME << "\t" << st.BALANCE << endl;
		fbin.close();
}
//==============================================================

//====== InitializeFile() ======================================
void InitializaFile()
{
	  fstream ftxt, fbin;
	  ftxt.open("file.txt", ios::in);
	  fbin.open("file.raf", ios::out | ios::binary);
	  RECORD st;int pos;
	  string lastName; string firstName; int id; double balance;
	  string line;
	  while(getline(ftxt, line))
	  {		
		stringstream linestream(line);
		linestream >> id;
		getline(linestream, lastName, ',');
		getline(linestream, firstName, ' ');
		linestream >> balance;
		st.ID = id; st.LAST_NAME = StrToCharPtr(lastName); st.FIRST_NAME = StrToCharPtr(firstName); st.BALANCE = balance;
		pos = (st.ID/10-1)*sizeof(st);
		fbin.seekp(pos,ios::beg);
		fbin.write((char*)&st, sizeof(st));
	  }
	  ftxt.close();
	  fbin.close();
}
//==============================================================

//====== WriteTextFile() =======================================
void WriteTextFile()
{
	RECORD st;
	fstream ftxt, fbin;
	ftxt.open("file.txt", ios::out);
	fbin.open("file.raf", ios::in|ios::binary);
	fbin.read((char*)&st, sizeof(st));
	while(true)
	{
		if(st.ID != 0 && st.BALANCE != 0)
			ftxt << st.ID << " " << st.LAST_NAME << "," << st.FIRST_NAME << " " << st.BALANCE << endl;
		fbin.read((char*)&st, sizeof(st));
		if(fbin.fail()) break;
	}
	fbin.close();
	ftxt.close();
}
//==============================================================

//====== StrToCharPtr() ========================================
char * StrToCharPtr(string str)
{
	char * st = new char[str.size()+1];
	strcpy(st, str.c_str());
	return st;
}
//==============================================================

//====== DisplayMenu() =========================================
void DisplayMenu()
{
	  cout << "------------------ Bank of Americana ------------------\n"
	   << "1.  Display all\n"
	   << "2.  Display record when ID is given\n"
	   << "3.  Deposit\n"
	   << "4.  Withdraw\n"
	   << "5.  Close account\n"
	   << "6.  Exit\n";
}
//==============================================================

/*OUTPUT
------------------ Bank of Americana ------------------
1.  Display all
2.  Display record when ID is given
3.  Deposit
4.  Withdraw
5.  Close account
6.  Exit

Enter your selection: 1

These are the contents of the file
10       Nixon,Kathy    100.1
20       Reagan,Ron     200.2
30       Clinton,Bill   300.3
40       Bush,Barbara   400.4
50       Carter,Jimmy   500.5
60       Bush,George    600.6
90       Obama,Barack   900.9

------------------ Bank of Americana ------------------
1.  Display all
2.  Display record when ID is given
3.  Deposit
4.  Withdraw
5.  Close account
6.  Exit

Enter your selection: 2
Enter ID to search: 60

These are the contents of the search
60       Bush,George    600.6

------------------ Bank of Americana ------------------
1.  Display all
2.  Display record when ID is given
3.  Deposit
4.  Withdraw
5.  Close account
6.  Exit

Enter your selection: 3
Enter account ID: 40
Enter deposit amount: 125.36

These are the contents of the file
10       Nixon,Kathy    100.1
20       Reagan,Ron     200.2
30       Clinton,Bill   300.3
40       Bush,Barbara   525.76
50       Carter,Jimmy   500.5
60       Bush,George    600.6
90       Obama,Barack   900.9

------------------ Bank of Americana ------------------
1.  Display all
2.  Display record when ID is given
3.  Deposit
4.  Withdraw
5.  Close account
6.  Exit

Enter your selection: 4
Enter account ID: 20
Enter withdrawal amount: 78.65

These are the contents of the file
10       Nixon,Kathy    100.1
20       Reagan,Ron     121.55
30       Clinton,Bill   300.3
40       Bush,Barbara   525.76
50       Carter,Jimmy   500.5
60       Bush,George    600.6
90       Obama,Barack   900.9

------------------ Bank of Americana ------------------
1.  Display all
2.  Display record when ID is given
3.  Deposit
4.  Withdraw
5.  Close account
6.  Exit

Enter your selection: 5
Enter account ID: 10
These are the contents of the file
20       Reagan,Ron     121.55
30       Clinton,Bill   300.3
40       Bush,Barbara   525.76
50       Carter,Jimmy   500.5
60       Bush,George    600.6
90       Obama,Barack   900.9

------------------ Bank of Americana ------------------
1.  Display all
2.  Display record when ID is given
3.  Deposit
4.  Withdraw
5.  Close account
6.  Exit

Enter your selection: 6
Press any key to continue . . .
*/

/* file.txt output
20  Reagan,Ron 121.55
30  Clinton,Bill 300.3
40  Bush,Barbara 525.76
50  Carter,Jimmy 500.5
60  Bush,George 600.6
90  Obama,Barack 900.9
*/