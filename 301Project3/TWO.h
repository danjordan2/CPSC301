//=========================================
// Name: Daniel Jordan
// Email: daniel_jordan@csu.fullerton.edu
// Class: CPSC 301
// Assignment: Project 3
// File: TWO.h
// ===========================================
using namespace std;
template <class T, int n>
class TWO
{
	private:
	struct PERSON
	{
		T  Id;
		float Balance;
	}; PERSON a[n]; fstream f;
	public:
	void ReadData(char fname[])
	{
		f.open(fname, ios::in);
		for(int i=0; i<n; ++i)
			f>>a[i].Id>>a[i].Balance;
		f.close();
	}
	void DisplayData( )
	{
	    cout << fixed << showpoint << setprecision(2);
	    for(int i=0; i<n; ++i)
	       cout<<left<<setw(5)<< a[i].Id<< "\t" <<right<<setw(5)<<a[i].Balance<<endl;
	}
};
