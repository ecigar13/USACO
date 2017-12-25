//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>


//solution from USACO website
using namespace std;

#define MAXN 160

int N;
int A[MAXN];
int B[MAXN];

int memo[MAXN][MAXN];

int solve(int x, int y) {
	//switch to solving the other recorder if one ends earlier than the other
	if (B[y] < B[x]) return solve(y, x);

	//if the program is already covered, return
	int& ref = memo[x][y];
	if (ref != -1) return ref;

	
	ref = 0;

	//if the recorded program's end is smaller than the next program's start
	// and the program is not recorded yet in the other recorder
	for (int i = 0; i < N; i++) {
		if (B[x] <= A[i] && i != y) {

			//process the program
			ref = max(ref, 1 + solve(i, y));
		}
	}

	return ref;
}

int main() {
	freopen("recording.in", "r", stdin);
	freopen("recording.out", "w", stdout);

	cin >> N;
	assert(1 <= N && N <= 150);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	A[N] = B[N] = 0;

	memset(memo, -1, sizeof(memo));
	cout << solve(N, N) << endl;
	return 0;
}