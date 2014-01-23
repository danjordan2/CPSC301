//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 6
// File: queuepk.h
// ===========================================
template <class T>
class queuepk
{
private:
	struct node
	{
		T info;
		node * next;
	};
	node *front, *rear;
public:
	queuepk()
	{
		front = NULL;
		rear = NULL;
	}
	void pushq(T x)
	{
		node *p;
		p = new(node);
		p->info = x;
		p->next=NULL;
		if(front==NULL)
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
		T x;
		x = front->info;
		front = front->next;
		delete(p);
		return x;
	}
};
