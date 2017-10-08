/*
ID: ecigar
LANG: C++
TASK: slowdown
*/

//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


//she moves at 1 / 2 meter
//per second after slowing down once, then 1 / 3 meter per second after slowing
//down twice, and so on.
class Bessie {
public:
	double speed;
	double curTime;
	double curPos;
	double length;
	double denominator;

	Bessie();
};
Bessie::Bessie()
{
	speed = 1;
	curTime = 0;
	curPos = 0;
	length = 1000;
	denominator = 1;
}

void dChange(vector<int> &d, int & dPos, Bessie*b) {
	double temp = (d[dPos] - b->curPos) *b->denominator;
	b->curTime += temp;
	b->curPos = d[dPos];

	b->denominator++;
	b->speed = 1 / b->denominator;
	dPos++;

}
void tChange(vector<int> &t, int & tPos, Bessie*b) {
	double temp = (t[tPos] - b->curTime) / b->denominator;
	b->curPos += temp;
	b->curTime = t[tPos];

	b->denominator++;
	b->speed = 1 / b->denominator;
	tPos++;

}

void tdChange(vector<int> &t, vector<int> &d, int & tPos, int & dPos, Bessie* b) {
	b->curPos = d[dPos];
	b->curTime = t[tPos];

	b->denominator += 2;
	b->speed = 1 / b->denominator;
	tPos++;
	dPos++;
}
void slowdown(vector<int> &t, vector<int> &d, int size, Bessie * b) {
	double distTime = 0;
	double distDist = 0;
	int tPos = 0;
	int dPos = 0;

	for (int i = 0; i < size; i++) {
		//cout << distTime << ' ' << distDist << endl;
		//cout << "before: curTime: " << b->curTime << " curPos " << b->curPos << endl;

		if (tPos > (t.size() - 1))
			dChange(d, dPos, b);
		else if (dPos > (d.size() - 1))
			tChange(t, tPos, b);
		else {
			distTime = b->speed * (t[tPos] - b->curTime);
			distDist = d[dPos] - b->curPos;


			if (distTime > distDist) {
				dChange(d, dPos, b);
			}
			else if (distTime < distDist) {
				tChange(t, tPos, b);
			}
			else {
				tdChange(t, d, tPos, dPos, b);
				i++;
			}
		}
		//cout << "after: curTime: " << b->curTime << " curPos " << b->curPos << endl;

	}
	b->curTime += ((b->length - b->curPos) * b->denominator);

}
int main() {

	ifstream fin("slowdown.in");
	ofstream fout("slowdown.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	Bessie* b = new Bessie();
	//read in
	int n, temp;
	char s;
	vector<int> t;
	vector<int> d;

	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> s;
		fin >> temp;
		if (s == 'D') {
			d.push_back(temp);
		}
		else {
			t.push_back(temp);
		}
	}

	sort(t.begin(), t.end());
	sort(d.begin(), d.end());


	slowdown(t, d, n, b);


	int currentTime = (int)b->curTime;
	double fraction = b->curTime - currentTime;

	if (fraction < 0.5)
		cout << currentTime << "\n";
	else
		cout << currentTime + 1 << "\n";

	//cout << endl << curTime << endl << curPos << endl << denominator;
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}

