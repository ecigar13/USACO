/*
ID: ecigar
LANG: C++
TASK: skidesign
*/

#include "stdafx.h"
#include <iostream>
#include<queue>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

int fill(vector<int>&h) {
	int maxSum = 0;
	int tempSum = 0;


}
int main() {

	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int size, temp;
	vector<int> h;

	fin >> size;
	while(fin>>temp) {
		h.push_back(temp);
	}
	sort(h.begin(),h.end());
	//for (int i = 0; i < size; i++) cout << h[i] << ' ';


	cout << fill(h);
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}
