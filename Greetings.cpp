/*
ID: ecigar
PROG: gift1
LANG: C++11
*/
//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
using namespace std;

int main() {


	ofstream fout("greetings.out");
	ifstream fin("greetings.in");
	//get friends

	int bessie(0), elsie(0);

	fin >> bessie>>elsie;

	/* 4 vars: Bf Bt Ef Et =0
	2 arrays to keep track
	for loop:
	int move, char dir
	read in both
	if dir = L, then move *=-1; then put in array
	else, just put in array.
	int count(0)
	*/

	int beforeB(0), afterB(0), beforeE(0), afterE(0);
	char *b = new char[1000000];
	char *e = new char[1000000];
	int bstep(0), estep(0);
	int move(0);
	char dir;
	int cross = 0;
	for (int i = 0; i < bessie; i++) {
		fin >> move >> dir;
		for (int j = 0; j < move; j++)
			b[bstep++] = dir;
	}
	for (int i = 0; i < elsie; i++) {
		fin >> move >> dir;
		for (int j = 0; j < move; j++)
			e[estep++] = dir;
	}

	int maxStep = max(bstep, estep);

	for(int i(0);i<maxStep;i++)
	{
		if (b[i] == 'L')
			afterB = beforeB - 1;
		else if (b[i] == 'R')
			afterB = beforeB + 1;

		if (e[i] == 'L')
			afterE = beforeE - 1;
		else if (e[i] == 'R')
			afterE = beforeE + 1;

		if (afterB == afterE) {
			if (beforeB != beforeE)
				cross++;
		}
		else if (afterB == beforeE && afterE == beforeB)
			cross++;

		beforeB = afterB;
		beforeE = afterE;
	}


	fout << cross << endl;
	fout.close();
	delete[] b, e;

	return 0;
}
