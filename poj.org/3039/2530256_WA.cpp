#include <iostream>

using namespace std;

const double PRE = 1e-12;

double myabs(double d)
{
	if (d < 0)
	{
		return -d;
	}
	else
	{
		return d;
	}
}

int main()
{
	int n, m, i, s1, s2;
	double ans, tar;
	int ans1, ans2;
	cin >> n >> m;
	tar = (double)n / (double)m;
	ans = 10;
	
	for (i = 1; i <= 32767; ++i)
	{
		if (((n * i) % m) == 0)
		{
			s1 = (n * i / m) - 1;
			s2 = (n * i / m) + 1;
		}
		else
		{
			s1 = (n * i / m);
			s2 = s1 + 1;
		}
		if (ans > myabs((double(s1) / (double)i) - tar) + PRE)
		{
			ans = myabs((double(s1) / (double)i) - tar);
			ans1 = s1;
			ans2 = i;
		}
		if (ans > myabs((double(s2) / (double)i) - tar) + PRE)
		{
			ans = myabs((double(s2) / (double)i) - tar);
			ans1 = s2;
			ans2 = i;
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
