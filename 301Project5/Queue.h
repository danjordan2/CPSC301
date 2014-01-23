//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 5
// File: Queue.h
// ===========================================
class Queue
{
private:
	struct node
	{
		int data;
		node * next;
	};
	node * front, * rear;

public:
	Queue() { front = NULL; rear = NULL;}

	void pushq(int x)
	{
		node * p;
		p = new(node);
		p->data = x;
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
	bool Emptyq(int i)
	{
		if(H[i]== NULL)
			return true;
		else
			return false;
	}
	int popq(int i)
	{
		Node * p = H[i];
		int data;
		data = H[i]->data;
		H[i] = H[i]->next;
		delete(p);
		return data;
	}
};
