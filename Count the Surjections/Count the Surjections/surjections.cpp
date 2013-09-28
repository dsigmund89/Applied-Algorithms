// surjections.cpp
// David Sigmund
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned long long POW(int m, int n)
{
	unsigned long long s = m;
	for (int i = n; i > 1; i--)
	{
		s *= m; 
	}
	return s;
}

unsigned long long Combinations(int n, int i)
{
	unsigned long long combination = 0;

	if(i == 0 || n == 0 || i == n)
		return 1;
	else
	{
		unsigned long long temp1 = Combinations(n-1,i-1);
		unsigned long long temp2 = Combinations(n-1,i);
		combination = temp1 + temp2;
	}
	return combination;
}

unsigned long long getSurjection(int m, int n)
{
	unsigned long long s = 0;

	if(n == 1)
	{
		s = 1;
	}
	else if(m < n)
	{
		s = 0;
	}
	else if(m == n)
	{
		unsigned long long tempM = m;

		for(int i = (m-1); i > 0; i--)
		{
			tempM = tempM * i;
		}
		s = tempM;
	}
	else if(n > 1 && m > n)
	{
		unsigned long long summation = 0;

		for(int i = 1; i <= (n-1); i++)
		{
			summation = summation + (Combinations(n,i)*getSurjection(m,i));
		}
			s = POW(n,m) - summation;
	}
	return s;
}
void main () {

	int m = 0;
	int n = 0;
	unsigned long long s = 0;

	ifstream fin ("surjections.in");
	if (fin) {
		ofstream fout ("surjections.out");

		while(fin >> m >> n)
		{
			if(!(m == 0 && n == 0))
			{
				s = getSurjection(m,n);
				fout << "S(" << m << "," << n << ") = " << s << endl;
			}
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
	cout << "Complete!\n";
	system("Pause");
}