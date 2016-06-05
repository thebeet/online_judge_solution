#include <stdio.h>
#include <string.h>
#include <math.h>

char opr[100010];

int main()
{
	long i, l, n, m;
	double x_begin, y_begin, x_end, y_end;
	scanf("%ld%ld", &n, &m);
	scanf("%lf%lf", &x_begin, &y_begin);
	scanf("%lf%lf", &x_end, &y_end);
	scanf("%s", opr);
	l = strlen(opr);
	for (i = 0; i < l; i++)
	{
		switch(opr[i])
		{
			case 'F':
				y_begin = -y_begin;
				break;
			case 'B':
				y_begin = m + (m - y_begin);
				break;
			case 'L':
				x_begin = -x_begin;
				break;
			case 'R':
				x_begin = n + (n - x_begin);
				break;
		}
	}
	printf("%lf\n",sqrt(1.0 * ((x_begin - x_end) * (x_begin - x_end) + (y_begin - y_end) * (y_begin - y_end))));		
	return 0;
}			
	