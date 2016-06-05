#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int k;
	double p;
	double ans1(0.0), ans2(0.0);
	while ((cin >> k), k > 0)
	{
		cin >> p;
		ans1 = k / p;
		ans2 = 2 * ans1 / p - ans1;
		printf("%.3lf %.3lf\n", ans1, ans2);
	}
	return 0;
}
