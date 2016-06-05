#include <stdio.h>
#include <math.h>

int main()
{
	double l, p, pi;
	int i;
	pi = acos(0.0) * 2.0;
	while (scanf("%lf", &l) != EOF)
	{
		if (l < 1)
		{
			p = 2 * l / pi;
		}
		else
		{
			p = 2 * (acos(1.0 / l) - sqrt(l * l - 1.0) + l) / pi;
		}
		
		p = p / (1 - p);
		
		for (i = 1; ((double)(1000 - i + 1) / (double)i * p) > 1.0; ++i);
		
		printf("%d\n", i - 1);
	}
	return 0;
}
