//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 9
// File: 301Project9-2.cpp
// ===========================================
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct node
{
	char letter;
	string morse;
	node * left;
	node * right;
};
struct data
{
	char letter;
	string morse;
};
void insert(data x, node *&p);
void displayInorder(node * p);
void searchNode(string letter, node * p, node *&found);
//26 letters and one space character
const int MAX_LETTERS = 27;
int main()
{
	node * root = NULL;
	node * found;
	data a[MAX_LETTERS] = {{'A', ".-"},{'B', "-..."},{'C', "-.-."},
						   {'D', "-.."},{'E', "."},{'F', "..-."},
						   {'G', "--."},{'H', "...."},{'I', ".."},
						   {'J', ".---"},{'K', "-.-"},{'L', ".-.."},
						   {'M', "--"},{'N', "-."},{'O', "---"},
						   {'P', ".--."},{'Q', "--.-"},{'R', ".-."},
						   {'S', "..."},{'T', "-"},{'U', "..-"},
						   {'V', "...-"},{'W', ".--"},{'X', "-..-"},
						   {'Y', "-.--"},{'Z', "--.."},{' ', "----"}}; // Four dashes indicate space

	for(int i=0; i<MAX_LETTERS; i++)
		insert(a[i], root);

	string sentence = ".--. .- -.-. -.- ---- -- -.-- ---- -... ---"
					  " -..- ---- .-- .. - .... ---- ..-. .. ...- ."
					  " ---- -.. --- --.. . -. ---- .-.. .. --.- ..-"
					  " --- .-. ---- .--- ..- --. ...";

	cout << "Answer: ";
    istringstream iss(sentence);
    while(iss)
    {
    	string letter;
    	iss >> letter;
    	searchNode(letter, root, found);
    }
	return 0;
}
void insert(data x, node *&p)
{
	if(p==NULL)
	{
		p = new (node);
		p->letter = x.letter;
		p->morse= x.morse;
		p->left = NULL;
		p->right = NULL;
	}
	else if(x.morse < p->morse)
		insert(x, p->left);
	else
		insert(x, p->right);
}
void searchNode(string letter, node * p, node *&found)
{
	if(p==NULL)
		found = NULL;
	else
	{
		if(letter==p->morse)
			found = p;
		else if (letter<p->morse)
			searchNode(letter, p->left, found);
		else
			searchNode(letter, p->right, found);
		if(found==p)
			cout << p->letter;
	}
}
/*OUTPUT
Answer: PACK MY BOX WITH FIVE DOZEN LIQUOR JUGS
 */
