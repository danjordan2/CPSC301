//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 9
// File: BSH.h
// ===========================================
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <class T>
class BST
{
private:
	struct node
	{
		T info;
		int frequency;
		node * left;
		node * right;
	};node * root;

public:
	BST() { root = NULL;}
	void DispTree() { Display(root);}
	void DispSideway(){ int nSpace = 0; Display(root, nSpace);}
	void Insert(T x) { AddNode(x, root);}
	node * Search(T x)
	{
		node * found;
		SearchNode(x, root, found);
		return found;
	}
	~BST() { DelTree(root);}
	void AddNode(T x, node *&p)
	{
		if(Search(x) == NULL)
		{
			if(p==NULL)
			{
				p=new(node);
				p->info = x;
				p->frequency+=1;
				p->left = NULL;
				p->right = NULL;
			}
			else
				AddNode(x, x<p->info ? p->left : p->right);
		}
	}
	void Display(node * p)
	{
		if(p!= NULL)
		{
			Display(p->left);
			cout << "Number: " << p->info << ", Frequency: " << p->frequency << endl;
			Display(p->right);
		}
	}
	void Display(node * p, int nSpace)//-----sideways
	{
		if(p!=NULL)
		{
			Display(p->right, nSpace +=6);
			cout << setw(nSpace) << p->info << endl;
			Display(p->left, nSpace);
		}
	}
	void DelTree(node *& p)//----dispose tree
	{
		if(p!=NULL)
		{
			DelTree(p->left); DelTree(p->right);
			delete p;
			p = NULL;
		}
	}
	void SearchNode(T x, node * p, node *&f)
	{
		if(p==NULL)
			f = NULL;
		else
		{
			if(x==p->info)
			{
				p->frequency+=1;
				f = p;
			}
			else if(x<p->info)
				SearchNode(x, p->left, f);
			else
				SearchNode(x,p->right, f);
		}
	}
};
