#include <stdio.h>

int main()
{
	long i,n,m,k;
	scanf("%ld",&n);
	m=n%6;
	k=0;
	if ((m!=2) && (m!=3))
	{
		for (i=2;i<=n;i+=2)
		{
			k++;
			printf("%ld %ld\n",k,i);
		}
		for (i=1;i<=n;i+=2)
		{
			k++;
			printf("%ld %ld\n",k,i);
		}
	}
	else
	{
		if (((n/2)&1)==0)
		{
			for (i=n/2;i<=n;i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
			for (i=2;i<=((n/2)-2);i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
			for (i=n/2+3;i<=n-1;i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
			for (i=1;i<=((n/2)+1);i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
		}
		else
		{
			for (i=n/2;i<=n-1;i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
			for (i=1;i<=((n/2)-2);i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
			for (i=n/2+3;i<=n;i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
			for (i=2;i<=((n/2)+1);i+=2)
			{
				k++;
				printf("%ld %ld\n",k,i);
			}
		}
		if ((n&1)==1) printf("%ld %ld\n",n,n);
	}
	return 0;
}