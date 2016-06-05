#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(0) * 2.0;

int main()
{
	double w, h;
	while ((cin >> w >> h), w > 0)
	{
		double r = h / (2.0 * pi + 2.0);
		if (r + r > w)
		{
			r = w / 2.0;
		}
		double ans = r * r * pi * w;
		r = w / pi / 2.0;
		if (r * r * pi * (h - 2.0 * r) > ans)
		{
			ans = r * r * pi * (h - 2.0 * r);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
