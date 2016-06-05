#include <stdio.h>
#include <memory.h>

#define e 0.00000000000001

long ans[25];
bool flag;
long ansp;

long eq(double d1,double d2)
{
	if (d1-e>d2) return 1;
	if (d2-e>d1) return -1;
	return 0;
}

long gcd(long a,long b)
{
	long t;
	if (a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while (b>0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

void dfs(double r,long f,long p)
{
	long i;
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
	for (i=f;;i++)
	{
		while (eq(r,1.0/i)==-1)
		{
			i++;
		}
		if (i>100000) break;
		if (eq(p*1.0/i,r)==-1)
		{
			break;
		}
		ans[p]=i;
		dfs(r-1.0/i,i+1,p-1);
		if (flag) return;
	}
	return;
}


int main()
{
	long i,j,l,k,m,n;
	double d;
	scanf("%ld%ld",&m,&n);
	d=m*1.0/n;
	memset(ans,0,sizeof(ans));
	flag=false;
	dfs(d,1,20);
	if (flag)
	{
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

			

	
