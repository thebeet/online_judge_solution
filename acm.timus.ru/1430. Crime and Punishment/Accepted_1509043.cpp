#include <stdio.h>

#define INT long

INT gcd(INT a,INT b)
{
	INT r;
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
	INT i,a,b,n,x,y,g,ma,mb,mn,t,tt,mp,xx,yy;
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
		n/=a;
		printf("%ld %d\n",n,0);
	}
	else
	{
		g=gcd(a,b);
		ma=a/g;
		mb=b/g;
		mn=n/g;
		x=mn/ma;
		y=mn%ma;
		t=y%mb;
		mn=t;
		mp=0;
		if (t>0)
		{
			for (i=1;i<=x;i++)
			{
				t+=ma;
				tt=t%mb;
				if (tt<mn)
				{
					mn=tt;
					mp=i;
				}
				if (mn==0) break;
			}
		}
		xx=x-mp;
		yy=(n-a*xx)/b;
		if (flag) printf("%ld %ld\n",xx,yy);
		else printf("%ld %ld\n",yy,xx);
	}
	return 0;
}
