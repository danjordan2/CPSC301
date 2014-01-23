//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 6
// File: stackpk.h
// ===========================================
template <class T>
class stackpk
{
private:
	struct node
	{
		T info;
		node * next;
	};node * stack;
public:
	stackpk()
	{
		stack = NULL;
	}
	void pushs(T x)
	{
		node * p;
		p = new(node);
		p->info = x;
		p->next = NULL;
		if(stack==NULL)
		{
			stack=p;
		}
		else
		{
			p->next = stack;
			stack = p;
		}
	}
	bool Emptys()
	{
		if(stack == NULL)
			return true;
		else
			return false;
	}
	T pops()
	{
		node * p = stack;
		T x;
		x = stack->info;
		stack = stack->next;
		delete(p);
		return x;
	}
};
