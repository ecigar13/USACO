#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <complex>

using namespace std;

typedef long long ll;
typedef complex<ll> pnt;

static ll cross(const pnt &a, const pnt &b)
{
	return imag(conj(a) * b);
}

static ll cross(const pnt &a, const pnt &b, const pnt &c)
{
	return cross(b - a, c - a);
}

int main()
{
	ifstream in("sabotage.in");
	ofstream out("sabotage.out");

	int N;
	in >> N;
	vector<int> m(N);
	for (int i = 0; i < N; i++)
		in >> m[i];

	double ans = HUGE_VAL;
	pnt base(-(N - 2), -accumulate(m.begin(), m.begin() + (N - 2), 0));
	vector<pnt> hull;
	hull.push_back(pnt(1, m.back()));

	for (int i = N - 2; i > 0; i--)
	{
		int L = -1;
		int R = hull.size() - 1;
		while (R - L > 1)
		{
			int mid = (L + R) / 2;
			if (cross(base, hull[mid], hull[mid + 1]) > 0)
				R = mid;
			else
				L = mid;
		}
		pnt slope = hull[R] - base;
		ans = min(ans, (double)slope.imag() / slope.real());
		base.real()++;
		base.imag() += m[i - 1];
		pnt next = hull.back() + pnt(1, m[i]);
		while (hull.size() > 1 &&
			cross(hull[hull.size() - 2], hull[hull.size() - 1], next) <= 0)
			hull.pop_back();
		hull.push_back(next);
	}
	out << fixed << setprecision(3) << ans << '\n';
	return 0;
}