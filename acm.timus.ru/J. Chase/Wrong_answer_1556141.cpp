#include <stdio.h>
#include <memory.h>

#define e 0.0000000000000005

long ans[25];
long double dd[100010];
bool flag;
long ansp;

long eq(long double d1,long double d2)
{
	if (d1-e>d2) return 1;
	if (d2-e>d1) return -1;
	return 0;
}

long mx(long a,long b)
{
	return a>b?a:b;
}

void dfs(long double r,long f,long p)
{
	long i,b;
	if (eq(r,0)==0)
	{
		flag=true;
		ansp=p+1;
		return;
	}
	if (p==1)
	{
		return;
	}
	if (r<(long double)0.000000001) return;
	f=mx(long((long double)0.9999999999/r)-(long double)2.0,f);
	while ((f<=100000) && (eq(dd[f],r)==1))
	{
		f++;
	}
	for (i=f;i<=100000;i++)
	{
		if (eq(p*dd[i],r)==-1)
		{
			break;
		}
		ans[p]=i;
		dfs(r-dd[i],i+1,p-1);
		if (flag) return;
	}
	return;
}


int main()
{
	long i,j,l,k,m,n;
	long double d;
	scanf("%ld%ld",&m,&n);
	d=m*(long double)1.0/n;
	memset(ans,0,sizeof(ans));
	memset(dd,0,sizeof(dd));
	for (i=1;i<=100005;i++)
	{
		dd[i]=(long double)1.0/i;
	}
	flag=false;
	dfs(d,1,20);
	if (flag)
	{
		printf("%ld\n",20-ansp+1);
		for (i=ansp;i<=20;i++)
		{
			printf("%ld ",ans[i]);
		}
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}

