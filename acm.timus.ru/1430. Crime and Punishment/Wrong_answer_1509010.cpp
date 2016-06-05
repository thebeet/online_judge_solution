#include <stdio.h>

long mnn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

long gcd(long a,long b)
{
	long r;
	while (b>0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	long i,a,b,n,x,y,g,ma,mb,mn,t,mp;
	bool flag;
	scanf("%ld%ld%ld",&a,&b,&n);
	if (a<b)
	{
		x=a;
		a=b;
		b=x;
		flag=false;
	}
	else
	{
		flag=true;
	}
	if (a==b)
	{
		printf("%ld %d\n",n/a,0);
	}
	else
	{
		g=gcd(a,b);
		ma=a/g;
		mb=b/g;
		mn=n/g;
		x=mn/ma;
		y=mn%ma;
		mb=ma-mb;
		mb%=b;
		mn=y%b;
		t=y%b;
		mp=0;
		if (y>0)
		{
			for (i=1;i<=x;i++)
			{
				t=(t+mb)%b;
				if (t<mn)
				{
					mn=t;
					mp=i;
				}
				if (mn==0) break;
			}
		}
		if (flag) printf("%ld %ld\n",(x-mp),(n-a*(x-mp))/b);
		else printf("%ld %ld\n",(n-a*(x-mp))/b,(x-mp));
	}
	return 0;
}
