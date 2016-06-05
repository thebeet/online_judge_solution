#include <stdio.h>

long map[100][100];

int main()
{
	long i,j,ti,n,s;
	scanf("%ld%ld",&n,&s);
	for (i=1;i<=n;i++)
	{
		ti=0;
		for (j=i;j>=1;j--)
		{
			ti++;
			map[ti][j]=s;
			s=s%9+1;
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<i;j++)
			printf("  ");
		for (j=1;j<=(n-i);j++)
			printf("%ld ",map[i][j]);
		printf("%ld\n",map[i][n-i+1]);
	}
	return 0;
}
