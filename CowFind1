//My initial plan is to find the first ((, then count all )) to the right. But it gives wrong result to test case 3.

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
	int frontCount = 0;

	getline(fin, a);

	for (int i = 0; i < a.length() - 1;i++)
	{
		if (a[i] == '(' && a[i + 1] == '(')
			frontCount++;
		else if (a[i] == ')' && a[i + 1] == ')')
			pair += frontCount;
		
	}

	fout << pair << endl;
	fout.close();
	return 0;
}
