/*
ID: ecigar
LANG: C++
TASK: records
*/
//better solution: http://arknave.me/posts/2013-12-20-usaco-december-2013-bronze-editorial.html

//test case 6, 7 and 8 are wrong
//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;



int main() {

	ifstream fin("records.in");
	ofstream fout("records.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int size = 'Z' * 50;
	int hours;
	fin >> hours;
	int * group = new int[size];

	for (int i = 0; i < (size); i++)
		group[i] = 0;

	char c = fin.get();
	int total = 0;
	for (int i = 0; i <hours; i++) {
		
		while (true) {
			c = fin.get();
			//cout << c;
			if (c == '\n' || c== EOF)
				break;
			total += c;

		}
		//cout << total << endl;
		group[total]++;
		total = 0;
	}

	int max = 0;
	for (int i = 0; i < (size); i++) {
		/*if (group[i] != 0)
			cout << group[i] << ' ' << i << endl;;*/
		max = max > group[i] ? max : group[i];
	}
	fout << max;
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}
