#include <stdio.h>

int main()
{
	long i,x,y,z,n;
	scanf("%ld%ld%ld%ld",&x,&y,&z,&n);
	for (i=1;i<=n;i++)
		printf("0 0 %.12lf %ld %ld %.12lf\n",z*1.0/n*(i-1),x,y,z*1.0/n*i);
	return 0;
}
