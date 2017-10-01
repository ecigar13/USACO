/*
ID: ecigar
LANG: C++
TASK: relay
*/

//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

int trace(int*ar, int size, int targetPos) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (ar[i] == targetPos) {
			count += 1 + trace(ar, size, i + 1);
		}
	}
	return count;
}

int main() {

	ifstream fin("relay.in");
	ofstream fout("relay.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int size;
	fin >> size;
	int* ar = new int[size];
	for (int i = 0; i < size; i++) {
		fin >> ar[i];
	}
	int result = trace(ar, size, 0);
	cout << result;
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}
