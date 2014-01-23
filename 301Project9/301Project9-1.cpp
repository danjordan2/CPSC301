//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 9
// File: 301Project9-1.cpp
// ===========================================
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "BST-1.h"
using namespace std;
string strtolower(string str)
{
	for(int i=0; i<str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}
int main()
{
	char restart;
    char selection;
	BST<string> p;
	string sentence = "George Samsa awoke one morning only to discover "
					   "he had been transformed into a giant Cockroach";

    istringstream iss(sentence);
    while(iss)
    {
    	string word;
    	iss >> word;
    	p.Insert(strtolower(word));
    }
    do{
    cout << "a.\tDisplay the words in alphabetical order\n"
    	 << "b.\tdisplay the tree sideways\n"
    	 << "c.\tHow many leaves does the tree have\n"
    	 << "d.\tWhat is the height of the tree\n"
    	 << "e.\tSelect a random letter from a-z and delete all words that begin with that letter\n\n";

    cout << "Make a selection: ";
    cin >> selection;
    switch(tolower(selection))
    {
    case 'a':
    	cout << "\nWords in alphabetical order: ";
    	p.DispTree();
    	cout << endl;
    	break;
    case 'b':
    	p.DispSideway();
    	break;
    case 'c':
    	cout << "\nNumber of leaves in tree: ";
    	p.countNodes();
    	break;
    case 'd':
    	cout << "\nHeight of tree: ";
    	p.treeHeight();
    	break;
    }
    cout << "\nAgain(Y/N)?: ";
    cin >> restart;
    cout << endl;
    }while(toupper(restart) == 'Y');

	return 0;
}
/*OUTPUT
a.	Display the words in alphabetical order
b.	display the tree sideways
c.	How many leaves does the tree have
d.	What is the height of the tree
e.	Select a random letter from a-z and delete all words that begin with that letter

Make a selection: a

Words in alphabetical order:  a awoke been cockroach discover george giant had he into morning one only samsa to transformed

Again(Y/N)?: y

a.	Display the words in alphabetical order
b.	display the tree sideways
c.	How many leaves does the tree have
d.	What is the height of the tree
e.	Select a random letter from a-z and delete all words that begin with that letter

Make a selection: b
             transformed
                to
       samsa
                    only
               one
                 morning
                                into
                            he
                                 had
                                     giant
george
          discover
                     cockroach
                    been
       awoke
                 a


Again(Y/N)?: y

a.	Display the words in alphabetical order
b.	display the tree sideways
c.	How many leaves does the tree have
d.	What is the height of the tree
e.	Select a random letter from a-z and delete all words that begin with that letter

Make a selection: c

Number of leaves in tree: 17

Again(Y/N)?: y

a.	Display the words in alphabetical order
b.	display the tree sideways
c.	How many leaves does the tree have
d.	What is the height of the tree
e.	Select a random letter from a-z and delete all words that begin with that letter

Make a selection: d

Height of tree: 6

Again(Y/N)?: n
 */

