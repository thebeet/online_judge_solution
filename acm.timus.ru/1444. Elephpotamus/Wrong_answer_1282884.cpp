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
	long i,n,m,p;
	scanf("%d",&n);
	m=1000000;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (m>y[i])
		{
			m=y[i];
			p=i;
		}
	}
	for (i=1;i<p;i++)
	{
		jj[i]=jjj(p,i);
		id[i]=i;
		d[i]=(x[i]-x[p])*(x[i]-x[p])+(y[i]-y[p])*(y[i]-y[p]);
	}
	for (i=p+1;i<=n;i++)
	{
		jj[i-1]=jjj(p,i);
		id[i-1]=i;
		d[i-1]=(x[i]-x[p])*(x[i]-x[p])+(y[i]-y[p])*(y[i]-y[p]);
	}
	sort(1,n-1);
	printf("%d\n",n);
	if (p==1)
	{
		printf("%d\n",p);
		for (i=1;i<n;i++)
			printf("%d\n",id[i]);
	}
	else
	{
		for (i=1;i<n;i++)
			if (id[i]==1) break;
		for (;i<n;i++)
			printf("%d\n",id[i]);
		printf("%d\n",p);
		for (i=1;id[i]!=1;i++)
			printf("%d\n",id[i]);
	}
	return 0;
}
