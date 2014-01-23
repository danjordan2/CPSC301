//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 5
// File: Queue.h
// ===========================================
template<class T>
class Queue
{
private:
	struct node
	{
		T x;
		//int count;
		node * next;
	};
	node * front, * rear; 
	int count;
	
public:
	Queue() { front = NULL; rear = NULL; count = 0;}
	void pushq(T x)
	{
		node * p;
		p = new(node);

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
		count++;
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
		count--;
		node * p = front;
		T x;
		x = front->x;
		front = front->next;
		delete(p);
		return x;
	}
	bool search(int x, node * q)
	{
		bool duplicate = false;
		node * p = q;
		while(p!=NULL)
		{
		if(p->x == x)
			duplicate = true;
		else
			duplicate = false;
		p = p->next;
		}
		return duplicate;
	}
	int getCount()
	{
		return count;
	}
};
