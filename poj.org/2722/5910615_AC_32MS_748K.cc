#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = acos(0.0) * 2.0;

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		double xa, xb, ya, yb;
		cin >> xa >> ya >> xb >> yb;
		double as(0.0);
		double len(0.0);
		for (int i = 0; i < n; ++i)
		{
			double s;
			cin >> s;
			len += s * sqrt(2.0);
			as += s * s / 2.0;
		}
		double a1 = atan2(xb, yb);
		a1 += pi / 4.0;
		double a2 = pi / 2.0 - atan2(xa, ya) + pi / 4.0;
		double a3 = pi - a1 - a2;
		double l1 = len * sin(a1) / sin(a3);
		double l2 = len * sin(a2) / sin(a3);
		double s = l1 + l2 + len;
		s /= 2.0;
		double mas = sqrt(s * (s - l1) * (s - l2) * (s - len));
		printf("%.3f\n", mas - as);
	}
	return 0;
}
