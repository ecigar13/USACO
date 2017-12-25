//#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ifstream fin("recording.in");
	ofstream fout("recording.out");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int m, answer(0), end1(0), end2(0);
	fin >> m;
	vector<int> start(m);
	vector<int> stop(m);

	for (int i = 0; i < m; i++) {
		fin >> start[i] >> stop[i];
	}

	for (int c = 0; c < m; c++) {
		int low = INT_MAX;
		int lowIndex = -1;
		for (int i = 0; i < m; i++) {
			if (low > stop[i]) {
				low = stop[i];
				lowIndex = i;
			}
		}

		if (start[lowIndex] >= end1 && start[lowIndex] >= end2) {
			if (end1 < end2) {
				answer++;
				end2 = low;
			}
			else {
				answer++;
				end1 = low;
			}
		}
		else if (start[lowIndex] >= end1) {
			answer++;
			end1 = low;
		}
		else if (start[lowIndex] >= end2) {
			answer++;
			end2 = low;
		}
		stop[lowIndex] = INT_MAX;
	}




	fout << answer << endl;
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
}
