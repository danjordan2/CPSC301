//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 3
// File: 301Project3-7.cpp
// ===========================================
#include <iostream>
using namespace std;
class MyClasses
{
protected:
	string _Name[5];
	double _GPA[5];
	int _Age[5];
	int count;
public:
	MyClasses(){count = 0;}
	void GetData(string name, double gpa, int age)
	{
		_Name[count] = name;
		_GPA[count] = gpa;
		_Age[count] = age;
		count++;
	}
};
class CS131: public MyClasses
{
public:
	int CompAgeAve()
	{
		int totalAge=0;
		for(int i=0; i<count; i++)
			totalAge += _Age[i];
		return totalAge/count;
	}
	double CompGpaAve()
	{
		double totalGPA=0;
		for(int i=0; i<count; i++)
			totalGPA += _GPA[i];
		return totalGPA/count;
	}
	void NameAboveGpaAve()
	{
		double gpaAvg= CompGpaAve();
		for(int i=0; i<count; i++)
			if(_GPA[i] > gpaAvg)
				cout << _Name[i] << ", ";
	}
	void DisplayAll()
	{
		for(int i=0; i<count; i++)
		{
			cout << _Name[i] << ", " << _GPA[i] << ", " << _Age[i] << endl;
		}
	}
};
class CS301: public MyClasses
{
public:
	void DisplayAll()
	{
		for(int i=0; i<count; i++)
		{
			cout << _Name[i] << ", " << _GPA[i] << ", " << _Age[i] << endl;
		}
	}
	void DisplayMaxMin()
	{
		double maxGPA = 0;
		double minGPA = 0;
		for(int i=0; i<count; i++)
		{
			if(_GPA[i] > maxGPA)
				maxGPA = _GPA[i];
			if(i == 0)
				minGPA = _GPA[i];
			else if(_GPA[i] < minGPA)
				minGPA = _GPA[i];
		}
		cout << "Minimum GPA in CS301: " << minGPA << endl
			 << "Maximum GPA in CS301: " << maxGPA << endl;
	}
};
int main()
{
	CS131 CS131;
	CS301 CS301;

	CS301.GetData("Frank", 2.8, 21);
	CS301.GetData("Mary", 3.4, 22);
	CS301.GetData("Joe", 3.1, 24);
	CS301.GetData("Bill", 3.0, 20);
	CS301.GetData("Bob", 3.8, 23);

	CS131.GetData("Jake", 3.7, 21);
	CS131.GetData("Jimmy", 3.2, 20);
	CS131.GetData("Dan", 2.4, 23);
	CS131.GetData("Eric", 3.1, 22);
	CS131.GetData("Nick", 3.9, 25);

	cout << "Students enrolled in CS301\n\n"
	     << "Name, GPA, Age\n"
		 << "---------------------------\n";
	CS301.DisplayAll();
	cout << endl;

	CS301.DisplayMaxMin();
	cout << endl;

	cout << "Students enrolled in CS131\n\n"
	     << "Name, GPA, Age\n"
		 << "---------------------------\n";
	CS131.DisplayAll();
	cout << endl;

	cout << "Average Age of CS131 students: " << CS131.CompAgeAve() << endl
	     << "Average GPA of CS131 students: " << CS131.CompGpaAve() << endl;
	cout << "CS131 Students with GPA's above " << CS131.CompGpaAve() << ": "; CS131.NameAboveGpaAve();
	return 0;
}
/*OUTPUT

Students enrolled in CS301

Name, GPA, Age
---------------------------
Frank, 2.8, 21
Mary, 3.4, 22
Joe, 3.1, 24
Bill, 3, 20
Bob, 3.8, 23

Minimum GPA in CS301: 2.8
Maximum GPA in CS301: 3.8

Students enrolled in CS131

Name, GPA, Age
---------------------------
Jake, 3.7, 21
Jimmy, 3.2, 20
Dan, 2.4, 23
Eric, 3.1, 22
Nick, 3.9, 25

Average Age of CS131 students: 22
Average GPA of CS131 students: 3.26
CS131 Students with GPA's above 3.26: Jake, Nick,
 */
