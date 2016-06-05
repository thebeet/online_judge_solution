#include <stdio.h>

int main()
{
	long n,m,l,a;
	scanf("%ld%ld%ld",&n,&m,&l);
	while ((n!=0) || (m!=0) || (l!=0))
	{
		if (l<n)
		{
			a=l;
			l=n;
			n=a;
		}
		if ((l-n)%m!=0)
		{
			printf("No accounting tablet\n");
		}
		else
		{
			printf("%ld\n",((l-n)/m+2)/3);
		}
		scanf("%ld%ld%ld",&n,&m,&l);
	}
	return 0;
}
