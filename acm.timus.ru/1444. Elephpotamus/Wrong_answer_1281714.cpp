#include <stdio.h>

#define minn 0.000000001

long x[30010];
long y[30010];
long id[30010];
long d[30010];
double jj[30010];

long eq(double n1,double n2)
{
	if ((n1-minn)>n2) return 1;
	if ((n1+minn)<n2) return -1;
	return 0;
}

double jjj(long p1,long p2)
{
	if (x[p1]==x[p2])
	{
		if (y[p2]>y[p1])
			return 10000000;
		else
			return -10000000;
	}
	else
	{
		if (x[p2]>x[p1])
			return (y[p2]-y[p1])/(x[p2]-x[p1]);
		else
			return 20000000-(y[p2]-y[p1])/(x[p2]-x[p1]);
	}
}

void sort(long l,long r)
{
	long i,j,x2,t;
	double x,y;
	i=l;
	j=r;
	x=jj[(l+r)/2];
	x2=d[(l+r)/2];
	for (;;)
	{
		while ((eq(jj[i],x)==-1) || ((eq(jj[i],x)==0) && (d[i]<x2)))
			i++;
		while ((eq(jj[j],x)==1) || ((eq(jj[j],x)==0) && (d[j]>x2)))
			j--;
		if (i<=j)
		{
			y=jj[i];
			jj[i]=jj[j];
			jj[j]=y;
			t=d[i];
			d[i]=d[j];
			d[j]=t;
			t=id[i];
			id[i]=id[j];
			id[j]=t;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

int main()
{
	long i,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		jj[i]=jjj(1,i);
		id[i]=i;
		d[i]=(x[i]-x[1])*(x[i]-x[1])+(y[i]-y[1])*(y[i]-y[1]);
	}
	sort(2,n);
	printf("%d\n",n);
	for (i=1;i<=n;i++)
		printf("%d\n",id[i]);
	return 0;
}
