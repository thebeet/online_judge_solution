#include <stdio.h>

int main()
{
	double r,m;
	long y,i;
	scanf("%lf%lf%ld",&r,&m,&y);
	r=(100.0+r)/100.0;
	for (i=1;i<=y;i++)
	{
		m*=r;
	}
	printf("%ld\n",long(r));
	return 0;
}
