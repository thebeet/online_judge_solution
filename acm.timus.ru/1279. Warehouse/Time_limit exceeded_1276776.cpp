#include <stdio.h>

long h[10001];
long n;

void sort(long l,long r)
{
	long i,j,x,y;
	i=l;j=r;
	x=h[(i+j)/2];
	for (;;)
	{
		while (h[i]<x)
			i++;
		while (h[j]>x)
			j--;
		if (i<=j)
		{
			y=h[i];
			h[i]=h[j];
			h[j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

void turndown(long p)
{
	long pt,pt1;
	pt=p<<1;
	if (pt>n) return;
	pt1=pt+1;
	if ((pt1<=n) && (h[pt1]<h[pt]))
		pt=pt1;
	if (h[p]>h[pt])
	{
		pt1=h[p];
		h[p]=h[pt];
		h[pt]=pt1;
		turndown(pt);
	}
}

int main()
{
	long i,m,k;
	scanf("%d%d%d",&n,&m,&k);
	n*=m;
	for (i=1;i<=n;i++)
		scanf("%d",&h[i]);
	sort(1,n);
	for (i=1;i<=k;i++)
	{
		h[1]++;
		turndown(1);
	}
	printf("%d\n",h[1]);
	return 0;
}
