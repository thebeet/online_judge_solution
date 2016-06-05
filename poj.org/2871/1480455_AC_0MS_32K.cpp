#include <stdio.h>

int main()
{
	double a,b;
	scanf("%lf",&a);
	scanf("%lf",&b);
	while (b<300)
	{
		printf("%.2lf\n",b-a);
		a=b;
		scanf("%lf",&b);
	}
	printf("End of Output\n");
	return 0;
}
