#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>

/*
* Solution from USACO website for practice
*/
using namespace std;

int A[200000];
int B[200000];
int C[200000][2];
int V[100000];
vector<int> E[100000];

bool vis[100000][2];

int solve(int x, int m) {
	int& ref = C[x][m == 1];
	if (ref != -1) return ref;

	int u = B[x];
	if (vis[u][m == 1]) {
		int r = 0;
		for (int i = 0; i < E[u].size(); i++) {
			C[E[u][i] ^ 1][m == 1] = max(r, C[E[u][i] ^ 1][m == 1]);
			r = max(r, m * V[u] + C[E[u][i]][m == 1]);
		}
		r = 0;
		for (int i = E[u].size() - 1; i >= 0; i--) {
			C[E[u][i] ^ 1][m == 1] = max(r, C[E[u][i] ^ 1][m == 1]);
			r = max(r, m * V[u] + C[E[u][i]][m == 1]);
		}
		return ref;
	}
	vis[u][m == 1] = true;

	ref = max(0, m * V[u]);
	for (int i = 0; i < E[u].size(); i++) {
		if (x == (E[u][i] ^ 1)) continue;
		ref = max(ref, m * V[u] + solve(E[u][i], m));
	}
	return ref;
}

int main() {
	freopen("btree.in", "r", stdin);
	freopen("btree.out", "w", stdout);

	int N; cin >> N;
	assert(1 <= N && N <= 40000);
	for (int u = 1, id = 0; u < N; u++) {
		int v; cin >> v; v--;
		assert(v < u);
		A[id] = u;
		B[id] = v;
		E[u].push_back(id++);
		A[id] = v;
		B[id] = u;
		E[v].push_back(id++);
	}
	for (int i = 0; i < N; i++) {
		char ch; cin >> ch;
		V[i] = ch == '(' ? 1 : -1;
	}

	int res = 0;
	memset(vis, 0, sizeof(vis));
	memset(C, -1, sizeof(C));
	for (int u = 0; u < N; u++) {
		for (int i = 0; i < E[u].size(); i++) {
			int id = E[u][i];
			res = max(res, min(solve(id, 1), solve(id ^ 1, -1)));
		}
	}
	cout << res << endl;
}