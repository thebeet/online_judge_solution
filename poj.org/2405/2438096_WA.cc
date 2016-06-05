#include <stdio.h>
#include <math.h>

int main()
{
	double D, V;
	while (scanf("%lf%lf", &D, &V), D > 0.0000001)
	{
		printf("%lf\n", pow(D * D * D - 6 * V / acos(0) / 2.0, 1.0 / 3.0));
	}
	return 0;
}
