#include <stdio.h>

int main()
{
	__int64 n;
	scanf("%I64d",&n);
	n=n*(n+1)*(n+2)/2;
	printf("%I64d\n",n);
	return 0;
}
