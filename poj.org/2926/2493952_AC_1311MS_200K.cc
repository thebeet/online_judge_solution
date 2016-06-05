#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

double x[10];
double mx[32];
double mn[32];

int main()
{
	int i, j, k, n;
	double sum, ans;
	scanf("%d", &n);
	
	for (i = 0; i < 32; ++i)
	{ 
		mx[i] = -1e100;
		mn[i] = 1e100;
	}
	ans = 0;
	
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= 5; ++j)
		{
			scanf("%lf", &x[j]);
		}
		for (j = 0; j < 32; ++j)
		{
			sum = 0;
			for (k = 1; k <= 5; ++k)
			{
				if ((j & (1 << (k - 1))) > 0)
				{
					sum -= x[k];
				}
				else
				{
					sum += x[k];
				}
			}
			mx[j] = MAX(mx[j], sum);
			mn[j] = MIN(mn[j], sum);
		}
	}
	for (j = 0; j < 32; ++j)
	{
		ans = MAX(ans, mx[j] - mn[j]);
	}
	printf("%.2lf\n", ans);
	return 0;
}
