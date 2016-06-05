#include <stdio.h>
#include <memory.h>

long a[510][510];

int main()
{
	long i,j,n,k,l,s;
	scanf("%d",&n);
	k=0;
	l=n*n+1;
	s=n*n+n/2+1;
	for (i=2;i<=n;i+=2)
		for (j=1;j<=i;j++)
		{
			k++;
			a[j][i-j+1]=k;
		}
	for (i=((n+1)&1)+2;i<=n;i+=2)
		for (j=n;j>=i;j--)
		{
			k++;
			a[i+n-j][j]=k;
		}
	for (i=1;i<=n;i+=2)
		for (j=1;j<=i;j++)
		{
			l--;
			a[j][i-j+1]=l;
		}
	for (i=(n&1)+2;i<=n;i+=2)
		for (j=n;j>=i;j--)
		{
			l--;
			a[i+n-j][j]=l;
		}
	printf("%d\n",s);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
