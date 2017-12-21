
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
	//get friends

	int num = 0;
	fin >> num;
	//string array

	string* names=new string[num];
	//int array as 0s
	int* bal=new int[num];
	//get all string names
	string temp;
	int give(0), div(0), avg(0);

	for (int i = 0; i < num; i++)
	{
		fin >> names[i];
		bal[i] = 0;
	}
	
	for (int i = 0; i < num; i++)
	{
		//get give, div,avg
		//for each given, find that  name, 
		//find avg, subtract and add the average

		fin >> temp >> give >> div;
		avg = div ? give / div : 0;
		for (int k = 0; k < num; k++)
		{
			if (names[k].compare(temp)==0)
			{
				bal[k] -= (avg*div);
				break;
			}
		}

		for (int j = 0; j < div; j++)
		{
			fin >> temp;
			for (int k = 0; k < num; k++)
			{
				if (names[k].compare(temp)==0)
				{
					bal[k] += avg;
					break;

				}
			}
		}
	}

	for (int i = 0; i < num; i++)
		fout << names[i] << ' ' << bal[i] << endl;
	fout.close();
	return 0;
}
