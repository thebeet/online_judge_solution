#include <stdio.h>

long a[500010];
long m;

void qsort(long l,long r)
{
	long i,j,x,y;
	i=l;
	j=r;
	x=a[(i+l)>>1];
	for (;;)
	{
		while (a[i]>x) i++;
		while (a[j]<x) j--;
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
	if ((i<r) && (i<=m)) qsort(i,r);
	if ((l<j) && (j>=m)) qsort(l,j);
}

int main()
{
	long i,n;
	scanf("%d",&n);
	m=(n+1)>>1;
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	qsort(1,n);
	printf("%d\n",a[(n+1)>>1]);
	return 0;
}
