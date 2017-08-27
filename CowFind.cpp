//Time limit exceed in test 9 and 10. n^2 worst case.
/*
ID: ecigar
PROG: cowfind
LANG: C++11
*/
//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <cmath>
#include <random>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ofstream fout("cowfind.out");
	ifstream fin("cowfind.in");

	string a;
	int pair = 0;
	getline(fin, a);

	for (int i = 0;i<a.length()-1; i++)
	{
		if (a[i] == '(' && a[i + 1] == '(')
		{
			for (int j = i; j < a.length() - 1; j++)
			{
				if (a[j] == ')' && a[j + 1] == ')')
					pair++;
			}
		}
	}
	fout << pair << endl;
	
	return 0;
}
