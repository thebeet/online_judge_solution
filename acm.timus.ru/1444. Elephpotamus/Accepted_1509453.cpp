#include <stdio.h>

#define minn 0.00000000001

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
			return ((y[p2]-y[p1])*1.0/(x[p2]-x[p1]));
		else
			return (200000000+(y[p2]-y[p1])*1.0/(x[p2]-x[p1]));
	}
}

void swap(long &a,long &b)
{
	long tmp;
	tmp=a;
	a=b;
	b=tmp;
	return;
}

void dswap(double &a,double &b)
{
	double tmp;
	tmp=a;
	a=b;
	b=tmp;
	return;
}

void sort(long l,long r)
{
	long i,j,x2;
	double x;
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
			dswap(jj[i],jj[j]);
			swap(d[i],d[j]);
			swap(id[i],id[j]);
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
	double pp;
	scanf("%ld",&n);
	m=1000000;
	scanf("%ld%ld",&x[1],&y[1]);
	id[1]=1;
	for (i=2;i<=n;i++)
	{
		scanf("%ld%ld",&x[i],&y[i]);
		jj[i]=jjj(1,i);
		id[i]=i;
		d[i]=(x[i]-x[1])*(x[i]-x[1])+(y[i]-y[1])*(y[i]-y[1]);
	}
	sort(2,n);
	printf("%ld\n",n);
	printf("1\n");
	p=2;
	for (i=2;i<n;i++)
	{
		pp=jj[i]-jj[i+1];
		if (pp<0) pp=-pp;
		if (eq(pp,200000000.0)>-1)
		{
			p=i+1;
			break;
		}
	}
	for (i=p;i<=n;i++)
	{		
		printf("%ld\n",id[i]);
	}
	for (i=2;i<p;i++)
	{		
		printf("%ld\n",id[i]);
	}
	return 0;
}
