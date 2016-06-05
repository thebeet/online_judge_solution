#include <stdio.h>

int main()
{
	long n;
	scanf("%ld",&n);
	if (n==0)
	{
		printf("0 0\n");
		return 0;
	}
	printf("%ld ",n-1);
	if ((n&1)==1) printf("%ld\n",(n/2)*3);
	else printf("%ld\n",(n-1)/2*3+1);
	return 0;
}
