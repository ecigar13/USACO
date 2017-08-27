
/*
ID: ecigar
PROG: ride
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

int s_product(const char *s)
{
	int product = 1;
	for (const char *p = s; *p; p++)
	{
		product *= *p - 'A' + 1;
	}
	return product;
}
int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");

	string a, b;

	getline(fin, a);
	getline(fin, b);

	fout << ((s_product(a.c_str()) % 47) == (s_product(b.c_str()) % 47) ? "GO" : "STAY") << endl;
	return 0;
}
