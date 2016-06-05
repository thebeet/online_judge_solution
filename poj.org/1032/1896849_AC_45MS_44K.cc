#include <stdio.h>
#include <memory.h>

long a[100];

int main()
{
	long i,j,n,s;
	scanf("%ld",&n);
	memset(a,0,sizeof(a));
	s=0;
	for (i=2;((s+i)<=n);i++)
	{
		a[0]++;
		a[a[0]]=i;
		s+=i;
	}
	i=a[0];
	for (j=1;j<=(n-s);j++)
	{
		if (i!=0) a[i]++;
		else a[a[0]]++;
		i--;
	}
	for (i=1;i<a[0];i++)
		printf("%ld ",a[i]);
	printf("%ld\n",a[a[0]]);
	return 0;
}
