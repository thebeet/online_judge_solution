#include <stdio.h>
#include <math.h>

#define PRE 1e-7

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

double x, y, c;


double f(double z)
{
	return (c / sqrt(x - z) + c / sqrt(y - z));
}  

int main()
{
	double lo, hi, mid;
	while (scanf("%lf%lf%lf", &x, &y, &c) != EOF)
	{
		lo = 0;
		hi = MIN(x, y);
		x *= x;
		y *= y;
		while (lo + PRE < hi)
		{
			mid = (lo + hi) / 2.0;
			if (f(mid * mid) > 1.0)
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}
		printf("%.3lf\n", mid);
	}
	return 0;
}
