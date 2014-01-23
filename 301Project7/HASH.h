/*
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <int n>
class HASH
{
private:
	struct Node
	{
		int id;
		string name;
		double balance;
		Node * next;
	};Node *H[n];

public:
	HASH()
	{
		for(int i=0; i<n; i++)
			H[i] = NULL;
	}
	int Hash_Fun(int x)
	{
		return x % n;
	}
	void insert(string name, int id, double balance, int hashTable)
	{
		int x;
		if(hashTable == 1)
			x = (int(toupper(name[1])) + int(toupper(name[2])));
		else
			x = id;
		int i = Hash_Fun(x);
		Node * q;
		q = new(Node);
		q->name = name;
		q->id = id;
		q->balance = balance;
		q->next = H[i];
		H[i] = q;
	}
	void Display_Table()
	{
		ofstream writeFile;
		writeFile.open("data.txt", ios::trunc);

		Node * p;
		for(int i = 0; i<n; i++)
		{
			p = H[i];
			while(p!=NULL)
			{
				//Save updated data to file on each display
				writeFile << p->name << " " << p->id << " " << p->balance << "\n";
				cout << p->name << "\t" << p->id << "\t" << p->balance << endl;
				p = p->next;
			}
		}
		writeFile.close();
	}
	void closeAccount(int x)
	{
		int i = Hash_Fun(x);
		Node * p, * place;
		p = H[i];
		while(p!=NULL && p->id !=x)
		{
			place = p;
			p = p->next;
		}
		if(p==NULL)
			cout << x << " does not exist\n";
		else if(p==H[i])
		{
			H[i]=p->next;
			delete(p);
		}
		else
		{
			place->next = p->next;
			delete(p);
		}
	}
	void SearchName(string name)
	{
		int x = (int(toupper(name[1])) + int(toupper(name[2])));
		int i = Hash_Fun(x);
		Node * p = H[i];
		while(p!=NULL && p->name != name)
			p = p->next;
		if(p==NULL)
			cout << name << " is not found\n";
		else
		{
			cout << "Name\tID\tBalance\n";
			cout << p->name << "\t" << p->id << "\t" << p->balance << "\n\n";
		}
	}
	void withdraw(int id, double amount)
	{
		int i = Hash_Fun(id);
		Node * p = H[i];
		while(p!=NULL && p->id != id)
			p = p->next;
		if(p==NULL)
		{
			cout << "Customer " << id << " is not found\n";
			cout << "balance: " << H[i]->name;
		}
		else
			p->balance -= amount;
	}
	void deposit(string name, double amount)
	{
		int x = (int(toupper(name[1])) + int(toupper(name[2])));
		int i = Hash_Fun(x);
		Node * p = H[i];
		while(p!=NULL && p->name != name)
			p = p->next;
		if(p==NULL)
			cout << "Customer " << name << " is not found\n";
		else
			p->balance += amount;
	}
	void emptyHash()
	{
		for(int i=0; i<n; i++)
			H[i] = NULL;
	}
};
