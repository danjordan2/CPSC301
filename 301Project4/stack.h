//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 4
// File: stack.h
//=========================================
#ifndef STACK_H
#define STACK_H
template <class T, int n>
class stack
{
private: T element[n];
		 int counter;
public:
		 void ClearStack(){ counter=0;}
		 bool isEmpty()
		 {
			 if(counter == 0)
				 return true;
			 else
				 return false;
		 }
		 bool isFull()
		 {
			 if(counter==n)
				 return true;
			 else
				 return false;
		 }
		 void push(T x)
		 {
			element[counter] = x;
			counter++;
		 }
		 T pop()
		 {
			 counter--;
			 return element[counter];
		 }
		 T getElement(int x)
		 {
			return element[x];
		 }
};
#endif
