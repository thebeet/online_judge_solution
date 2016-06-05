#include <stdio.h>

long a[10001];
long n;

void s(long l,long r)
{
	long i,j,x,y;
	i=l;
	j=r;
	x=a[(l+r)/2];
	for (;;)
	{
		while (a[i]<x)
			i++;
		while (a[j]>x)
			j--;
		if (i<=j)
		{
			y=a[i];
			a[i]=a[j];
			a[j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if ((l<j)&&(j>=(n+1)/2)) s(l,j);
	if ((i<r)&&(i<=(n+1)/2)) s(i,r);
}

int main()
{
	long i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s(1,n);
	printf("%d\n",a[(n+1)/2]);
	return 0;
}