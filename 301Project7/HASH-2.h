#include <iostream>
#include <string>
using namespace std;
template <int n>
class HASH
{
private:
	struct Node
	{
		int data;
		Node * next;
	};Node *H[n], *front, *rear;

public:
	HASH()
	{
		for(int i=0; i<n; i++)
			H[i] = NULL;
	}
	int Hash_Fun(int x, int sortLevel)
	{
		if(sortLevel == 1)
			return x % n;
		else if(sortLevel == 2)
			return (x % 10)/n;
		else if(sortLevel == 3)
			return (x % 100)/n;
	}
	void push(int x, int sortLevel)
	{
		int i;
		if(sortLevel == 1)
			i = Hash_Fun(x,1);
		else if(sortLevel == 2)
			i = Hash_Fun(x,2);
		else if(sortLevel == 3)
			i = Hash_Fun(x,3);
		Node * p;
		p = new(Node);
		p->data = x;
		p->next = NULL;

		if(H[i] == NULL)
			H[i] = rear = p;
		else
		{
			rear = H[i];
			while(rear->next!=NULL)
				rear = rear->next;
			rear->next = p;
			rear = p;
		}
	}
	void Display_Table()
	{
		cout << endl;
		for(int i=0; i<n; i++)
		{
			while(!Emptyq(i))
			{
				cout << popq(i) << " ";
			}
		}
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
	void emptyHash()
	{
		for(int i=0; i<n; i++)
			H[i] = NULL;
	}
	bool Emptyq(int i)
	{
		if(H[i]== NULL)
			return true;
		else
			return false;
	}
};
