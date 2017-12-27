
#include <iostream>
#include <fstream>

/*
* This problem is similar to the horseshoe problem.
*/
using namespace std;
string s;
int main()
{
	ifstream in("typo.in");
	ofstream out("typo.out");

	in >> s;
	int ans = 0;
	int depth = 0;
	int closingSeen = 0; //since start of string
	int openingSeen = 0; //since last time with depth = 1

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			depth++;
			openingSeen++;
		}
		else
		{
			depth--;
			closingSeen++;
		}

		if (depth <= 1)
			openingSeen = 0;
		if (depth == -1)
		{
			ans = closingSeen;
			break;
		}
	}

	if (depth > 0)
		ans = openingSeen;

	out << ans << "\n";
	out.close();
	return 0;
}