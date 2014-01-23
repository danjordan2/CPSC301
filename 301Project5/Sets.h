//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 5
// File: Sets.h
// ===========================================
#include <iostream>
using namespace std;
template<class T>
class Sets
{
private:
	struct NODE
	{
		T element;
		NODE * next;
	}*list;
public:
	Sets(){ list = NULL;}
	~Sets(){};
	void Insert(T x)
	{
		NODE * p = list, * q = list, *r;
		r = new(NODE);
		r->element = x;
		while(p != NULL && p->element < x)
		{
			q = p;
			p = p->next;
		}
		if(p == list)
		{
			list = r;
			r->next = p;
		}
		else if(p == NULL)
		{
			q->next = r;
		}
		else
		{
			r->next = p;
			q->next = r;
		}
	}
	void Inter(Sets P, Sets Q)
	{
		NODE * p;
		NODE * q;
		for(p = P.list; p!=NULL; p = p->next)
		{
			for(q = Q.list; q!=NULL; q = q->next)
			{
				if(p->element == q->element)
					Insert(p->element);
			}
		}
	}
	void Union(Sets P, Sets Q)
	{
		NODE * p = P.list;
		NODE * q = Q.list;
		while(p!=NULL)
		{
			Insert(p->element);
			p = p->next;
		}
		while(q!=NULL)
		{
			if(isNotDuplicate(q->element))
				Insert(q->element);
				q = q->next;
		}
	}
	bool isNotDuplicate(int x)
	{
		NODE * p = list;
		while(p!=NULL)
		{
			if(p->element != x)
				return true;
			else
				return false;
		}
	}
	void display()
	{
		NODE * p = list;
		cout << "{";
		while(p!=NULL)
		{
			cout << " " << p->element << " ";
			p = p->next;
		}
		cout << "}\n";
	}
};
