#include <stdio.h>
#include <math.h>
int main()
{
	int n,m,s;
	while (scanf("%d",&n)!=EOF)
	{
		m=(int(sqrt(1+4*2*(n-1))-1)/2);
		s=m*(m+1)/2;
		printf("TERM %d IS %d/%d\n",n,n-s,m+2-(n-s));
	}
	return 0;
}
