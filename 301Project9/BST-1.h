//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 9
// File: BST-1.h
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
		node * left;
		node * right;
	};node * root;

public:
	BST() { root = NULL;}
	void DispTree() { Display(root);}
	void countNodes(){cout << count(root) << endl;}
	void treeHeight(){cout << height(root) << endl;}
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
		if(p==NULL)
		{
			p=new(node);
			p->info = x;
			p->left = NULL;
			p->right = NULL;
		}
		else
			AddNode(x, x<p->info ? p->left : p->right);
	}
	void Display(node * p)
	{
		if(p!= NULL)
		{
			Display(p->left);
			cout << p->info << " ";
			Display(p->right);
		}
	}
	int height(node * p)
	{
		if(p==NULL)
			return 0;
		else if(p->left == NULL && p->right == NULL)
			return 1;
		else
			return height(p->left)+height(p->right);
	}
	int count(node * p)
	{
		if(p==NULL)
			return 0;
		else if(p->left == NULL && p->right == NULL)
			return 1;
		else
			return 1+count(p->left)+count(p->right);
	}
	void Display(node * p, int nSpace)
	{
		if(p!=NULL)
		{
			Display(p->right, nSpace +=6);
			cout << setw(nSpace) << p->info << endl;
			Display(p->left, nSpace);
		}
	}
	void DelTree(node *& p)
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
				f = p;
			else if(x<p->info)
				SearchNode(x, p->left, f);
			else
				SearchNode(x,p->right, f);
		}
	}
};
