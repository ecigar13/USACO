//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <stdio.h>
using namespace std;

class Hshoe {
public:
	char ** h;
	int largest=0;
	int size=0;

	Hshoe(int n);
	void trace(int x, int y, int opened, int closed);
	void printh();

};
Hshoe::Hshoe(int n)
{
	size = n;
	largest = 0;
	h = new char*[size];
	for (int i = 0; i < size; i++)
		h[i] = new char[size];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			h[i][j] = 0;
		}
	}
}
void Hshoe::trace(int x, int y, int opened, int closed)
{
	if (h[x][y] == '0') return;
	if (h[x][y] == '(')
		opened++;
	else closed++;
	if (h[x][y] == '(' && closed > 0) return;
	if (opened == closed) {
		largest = ((opened << 1) > largest) ? (opened << 1) : largest;
		return;
	}

	char temp = h[x][y];
	h[x][y] = '0';

	if (x + 1 < size)
		trace(x + 1, y, opened, closed);
	if (y + 1 < size)
		trace(x, y + 1, opened, closed);
	if (x - 1 >= 0)
		trace(x - 1, y, opened, closed);
	if (y - 1 >= 0)
		trace(x, y - 1, opened, closed);

	h[x][y] = temp;


	return;
}

void Hshoe::printh()
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout<<h[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {


	ofstream fout("hshoe.out");
	ifstream fin("hshoe.in");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int size(0);
	fin >> size;
	
	char temp;
	Hshoe shoe =  Hshoe(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fin >> temp;
			shoe.h[i][j] = temp;
			//fin.get(shoe.h[i][j]);
		}
	}

	shoe.trace(0, 0, 0, 0);
	fout << shoe.largest;
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}
