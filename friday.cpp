/*
ID: ecigar
LANG: C++
TASK: friday
*/
//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <stdio.h>
using namespace std;

class Leap {
public:
	int dur;
	int day;   //day of week (Monday...)
	int date;
	int year;
	int dayInYear;
	int* freq;    //0 = Sun, 1=Mon...
	int dayMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };

	Leap(int y);
	bool leapYear(int y);
	void countDays();
	void printFreq();
};

int main() {

	ifstream fin("friday.in");
	ofstream fout("friday.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());
	int y = 0;
	fin >> y;
	Leap* count = new Leap(y);

	count->countDays();
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}
Leap::Leap(int y)
{
	dur = y;
	day = 2;
	date = 1;
	year = 1900;
	dayInYear = leapYear(year) ? 366 : 365;
	freq = new int[7];
	for (int i = 0; i < 7; i++) {
		freq[i]=0;
	}


}
bool Leap::leapYear(int y)
{

	if (y % 100 == 0) {
		if(y % 400 == 0)
			return true;
		if (y % 400 != 0)
			return false;
	}
	else if (y % 4 == 0)
		return true;
	return false;
}
void Leap::countDays()
{
	for (int i = year; i < dur + year; i++) {
		bool leapY = leapYear(i);
		if (leapY) {
			dayMonth[1] = 29;
		}
		else dayMonth[1] = 28;

		//cout << leapY << ' ' << i << endl;

		for (int i = 0; i < 12; i++) {
			date += 12;
			int day = date% 7;
			freq[day]++;
			date = date+dayMonth[i]-13+1;

		}
	}

	this->printFreq();
}

void Leap::printFreq()
{
	cout << freq[6];

	for (int i = 0; i < 6; i++) {
		cout << ' '<<freq[i];
	}
	cout << endl;
}
