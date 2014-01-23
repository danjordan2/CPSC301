//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 6
// File: queuepk-2.h
// ===========================================
#include <iostream>
using namespace std;
template<class T>
class queuepk
{
private:
	struct node
	{
		T coif;
		int pwr;
		T x;
		node * next;
	};
	node * front, * rear;

public:
	queuepk() { front = NULL; rear = NULL;}

	void pushq(T coif, int pwr, T x)
	{
		node * p;
		p = new(node);
		p->coif = coif;
		p->pwr = pwr;
		p->x = x;
		p->next = NULL;
		if(front == NULL)
		{
			front = p;
			rear = p;
		}
		else
		{
			rear->next = p;
			rear = p;
		}
	}
	bool Emptyq()
	{
		if(front == NULL)
			return true;
		else
			return false;
	}
	T popq()
	{
		node * p = front;
		T coif;
		int pwr;
		T x;
		coif = front->coif;
		pwr = front->pwr;
		x = front->x;
		front = front->next;
		delete(p);
		if(coif != 0 && pwr != 0)
			cout << coif << "X" << "^" << pwr;
		return coif*pow(x, pwr);
	}
};
