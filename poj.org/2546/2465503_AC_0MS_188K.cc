#include <stdio.h>
#include <math.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
	double x1, y1, r1, x2, y2, r2, a1, a2, h;
	double d, pi;
	pi = acos(0) * 2.0;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d >= r1 + r2)
	{
		printf("0.000\n");
	}
	else if (d <= (MAX(r1 ,r2) - MIN(r1, r2)))
	{
		printf("%.3lf\n", pi * MIN(r1 ,r2) * MIN(r1 ,r2));
	}
	else
	{
		a1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
		a2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
		h = fabs(sin(a1) * r1);
		printf("%.3lf\n", a1 * r1 * r1 + a2 * r2 * r2 - h * d);
	}
	return 0;
}
