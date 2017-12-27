#include <iostream>
#include <fstream>
#include <string>
#define MAX_N 100


/*
* No time to code so this is my solution withotu coding:
* There are two sub problems: finding regions that human can see and finding regions that cow can see
* Use recursion
* Floodfill algorithm to find all the cells in the same region, then tag them with true or false. 
* Keep a variable of regions that human/cow can see. If the current cell is visited and the next one is not visited,
* then add one more region. Then run the floodfill algorithm to fill that region with true values.
*/
using namespace std;

string A[MAX_N];
int N;
bool valid[256][256];
bool visited[MAX_N][MAX_N];

void visit(int i, int j)
{
	if (visited[i][j]) return;
	visited[i][j] = true;
	if (i > 0 && valid[A[i - 1][j]][A[i][j]]) visit(i - 1, j);
	if (j > 0 && valid[A[i][j - 1]][A[i][j]]) visit(i, j - 1);
	if (i < N - 1 && valid[A[i + 1][j]][A[i][j]]) visit(i + 1, j);
	if (j < N - 1 && valid[A[i][j + 1]][A[i][j]]) visit(i, j + 1);
}

int solve(void)
{
	int count = 0;
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			visited[i][j] = false;
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			if (!visited[i][j]) {
				count++;
				visit(i, j);
			}
	return count;
}

int main(void)
{
	ifstream fin("cowart.in");
	fin >> N;
	for (int i = 0; i<N; i++) fin >> A[i];
	fin.close();

	valid['R']['R'] = valid['G']['G'] = valid['B']['B'] = true;
	int regions_human = solve();
	valid['R']['G'] = valid['G']['R'] = true;
	int regions_cow = solve();

	ofstream fout("cowart.out");
	fout << regions_human << " " << regions_cow << "\n";
	fout.close();

	return 0;
}