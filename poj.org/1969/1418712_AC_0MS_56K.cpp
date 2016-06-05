#include <stdio.h>
#include <math.h>
int main()
{
	long n,m,s;
	while (scanf("%d",&n)!=EOF)
	{
		m=(long(sqrt(1+4*2*(n-1))-1)/2);
		s=m*(m+1)/2;
		if ((m%2)==0) printf("TERM %d IS %d/%d\n",n,m+2-(n-s),n-s);
		else printf("TERM %d IS %d/%d\n",n,n-s,m+2-(n-s));
	}
	return 0;
}
