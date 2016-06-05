#include <stdio.h>
#include <math.h>
#include <memory.h>

#define es 0.0000000000001

long a[10][10];
double ans[10][10];
long nans[10];
long n;

long eq(double a,double b)
{
	if ((a+es)<b) return -1;
	if ((a-es)>b) return 1;
	return 0;
}

long check(double x,long p)
{
	long i;
	double s,ts;
	s=a[p][0];
	ts=1.0;
	for (i=1;i<=p;i++)
	{
		ts*=x;
		s+=ts*a[p][i];
	}
	return eq(s,0.0);
}

void work(long p)
{
	double a1[10];
	long n1;
	double a2[10];
	long n2;
	long f[10];
	long i,d;
	double xa,xb,xm;
	long ret;
	if (p==1)
	{
		nans[1]=1;
		ans[1][1]=-a[1][0]*1.0/a[1][1];
		return;
	}
	if (p==2)
	{
		d=a[2][1]*a[2][1]-4*a[2][0]*a[2][2];
		if (d>0)
		{
			nans[2]=2;
			ans[2][1]=(-a[2][1]*1.0-sqrt(d))/2.0*a[2][0];
			ans[2][1]=(-a[2][1]*1.0+sqrt(d))/2.0*a[2][0];
		}
		if (d==0)
		{
			nans[2]=2;
			ans[2][1]=(-a[2][1]*1.0/2.0*a[2][0]);
			ans[2][2]=(-a[2][1]*1.0/2.0*a[2][0]);
		}
		if (d<0)
		{
			ans[2][0]=0;
		}
		return;
	}
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	memset(f,0,sizeof(f));
	n1=0;
	n2=0;
	n1=nans[p-1]+2;
	a1[1]=-1000000000.0;
	f[1]=check(a1[1],p);
	for (i=1;i<=nans[p-1];i++)
	{
		a1[i+1]=ans[p-1][i];
		f[i+1]=check(a1[i+1],p);
	}
	a1[n1]=1000000000.0;
	f[n1]=check(a1[n1],p);
	for (i=2;i<=n1;i++)
	{
		if (f[i]==0)
		{
			n2++;
			a2[n2]=a1[i];
			continue;
		}
		if (f[i-1]==0)
		{
			n2++;
			a2[n2]=a1[i-1];
			continue;
		}
		if (f[i]*f[i-1]<0)
		{
			xa=a1[i-1];
			xb=a1[i];
			while (eq(xa+0.0000001,xb)<0)
			{
				xm=(xa+xb)/2.0;
				ret=check(xm,p);
				if (ret!=f[i])
				{
					xa=xm;
				}
				if (ret!=f[i-1])
				{
					xb=xm;
				}
			}
			n2++;
			a2[n2]=xa;
		}
	}
	nans[p]=n2;
	memcpy(ans[p],a2,sizeof(a2));
	return;
}

int main()
{
	long i,j;
	scanf("%ld",&n);
	for (i=n;i>=0;i--)
	{
		scanf("%ld",&a[n][i]);
	}
	for (i=n-1;i>=1;i--)
	{
		for (j=0;j<=i;j++)
		{
			a[i][j]=a[i+1][j+1]*(j+1);
		}
	}
	for (i=1;i<=n;i++)
	{
		work(i);
	}
	for (i=1;i<=nans[n];i++)
	{
		printf("%.10lf\n",ans[n][i]);
	}
	return 0;
}
