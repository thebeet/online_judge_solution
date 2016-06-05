#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAXN 710
#define INF 1e20
#define e 1e-10

long x[MAXN], y[MAXN];
double arg[MAXN];

bool cmp(double d1, double d2)
{
	return (d1 > d2) ? true : false;
}

long mx(long a, long b)
{
	return (a > b) ? a : b;
}

int main()
{
	long i, j, n, ans, p, fp;
	double d;
	while (scanf("%ld", &n), n > 0)
	{
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%ld%ld", &x[i], &y[i]);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (y[i] != y[j])
				{
					arg[j] = (double)(x[i] - x[j]) / (y[i] - y[j]);
				}
				else
				{
					arg[j] = 1e20;
				}
			}
			sort(arg + 1, arg + n + 1, cmp);
			p = 1;
			while (p <= n)
			{
				d = arg[p];
				fp = p + 1;
				while (((arg[fp] - d) > -e) && (fp <= n))
					fp++;
				if (d > 9e19) p++;
				ans = mx(ans, fp - p + 1);
				p = fp;
			}
		}
		printf("%ld\n", ans);
	}
	return 0;
}
