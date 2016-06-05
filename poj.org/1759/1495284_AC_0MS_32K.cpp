#include <stdio.h>

int main()
{
	long i,n;
	double a,b,t;
	scanf("%d%lf",&n,&a);
	n--;
	for(i=1;i<n;i++)
		if((t=(n-i)*(n*i-a)/i)>b)
			b=t;
	printf("%.2lf\n",b);
	return 0;
}
