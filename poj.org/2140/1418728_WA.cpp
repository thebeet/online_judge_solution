#include <stdio.h>
#include <math.h>
int main()
{
	int i,s,n;
	s=0;
	scanf("%d",&n);
	for (i=2;i<=sqrt(n*3);i++)
	{
		if (((i%2)==0) && (((n*2)%i)==0)) s++;
		if (((i%2)==1) && ((n%i)==0)) s++;
	}
	printf("%d\n",s);
	return 0;
}
