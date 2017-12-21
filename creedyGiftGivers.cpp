//Used map. This will give the wrong answer for USACO because map is already ordered by default.
/*
ID: ecigar
PROG: gift1
LANG: C++11
*/
//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <cmath>
#include <random>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	map<string, int> friends;
	string temp;
	int num(0), give(0), div(0), avg(0);
	fin >> num;

	//add all friends and zero fund
	for (int i = 0; i < num; i++)
	{
		fin >> temp;
		friends.insert(pair<string, int>(temp,0));
	}

	//change the funds given and received
	for (int i = 0; i < num; i++)
	{
		fin >> temp;
		fin >> give;
		fin >> div;
		if (div == 0)
			avg = 0;
		else avg = give / div;

		map<string, int>::iterator it = friends.find(temp);
		it->second += -avg*div;

		for (int j = 0; j < div; j++)
		{
			fin >> temp;
			it = friends.find(temp);
			it->second += avg;
		}
		
	}

	for (map<string, int>::iterator it = friends.begin(); it != friends.end(); it++)
	{
		fout << it->first << ' ' << it->second<<endl;
	}
	fout.close();
	return 0;
}
