#include <stdio.h>
struct frac
{
	long n,x,y;
};

long gcd(long a,long b)
{
	long r;
	if (b<0) b=-b;
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
	long t;
	frac f1,f2;
	char c,op;
	scanf("%d",&f1.n);
	f1.x=0;
	f1.y=1;
	scanf("%c",&c);
	if (c>20)
	{
		if (c==47)
		{
			f1.x=f1.n;
			f1.n=0;
			scanf("%d",&f1.y);
			scanf("%c",&c);
		}
		else
		{
			scanf("%d",&f1.x);
			scanf("%c",&c);
			scanf("%d",&f1.y);
			scanf("%c",&c);
		}
	}
	scanf("%c",&op);
	scanf("%c",&c);
	scanf("%d",&f2.n);
	f2.x=0;
	f2.y=1;
	scanf("%c",&c);
	if (c>20)
	{
		if (c==47)
		{
			f2.x=f2.n;
			f2.n=0;
			scanf("%d",&f2.y);
			scanf("%c",&c);
		}
		else
		{
			scanf("%d",&f2.x);
			scanf("%c",&c);
			scanf("%d",&f2.y);
			scanf("%c",&c);
		}
	}
	if (f1.n<0) f1.x=-f1.x;
	if (f2.n<0) f1.x=-f2.x;
	f1.x=f1.n*f1.y+f1.x;
	f2.x=f2.n*f2.y+f2.x;
	if ((op==43)||(op==45))
	