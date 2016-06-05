#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = 2.0 * acos(0);

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int n, m, t, c;
		double s[8];
		cin >> n >> m >> t >> c;
		s[0] = n * m * t * t;
		s[1] = 100.0 * ((t - c) * (t - c) * n * m + c * (t - c) * (n + m) + c * c);
		s[2] = 100.0 * ((t - c) * c * (n * (m - 1) + (n - 1) * m) + c * c * (n + m - 2));
		s[4] = 100.0 * (n - 1) * (m - 1) * c * c / 4.0 * pi;
		s[3] = 100.0 * s[0] - s[1] - s[2] - s[4];
		if (ti != 1)
		{
			cout << endl;
		}
		cout << "Case " << ti << ":" << endl;
		cout << "Probability of covering 1 tile  = ";
		printf("%.4lf%%\n", s[1] / s[0]);
		cout << "Probability of covering 2 tiles = ";
		printf("%.4lf%%\n", s[2] / s[0]);
		cout << "Probability of covering 3 tiles = ";
		printf("%.4lf%%\n", s[3] / s[0]);
		cout << "Probability of covering 4 tiles = ";
		printf("%.4lf%%\n", s[4] / s[0]);
	}
	return 0;
}
