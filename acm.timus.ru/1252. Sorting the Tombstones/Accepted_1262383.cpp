#include <stdio.h>

long ps[130010];

long gcd(long a,long b)
{
	long r;
	if (b>a)
	{
		r=a;
		a=b;
		b=r;
	}
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
	long i,n,m,t,s,tag;
	scanf("%d",&n);
	s=n-1;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m);
		ps[m]=i;
	}
	m=0;
	s=0;
	for (i=1;i<=130000;i++)
		if (ps[i]>0)
		{
			m++;
			t=m-ps[i];
			if (t<0) t=-t;
			s=gcd(s,t);
		}
	tag=s;
	if (tag==0)
	{
		printf("%d\n",n-1);
		return 0;
	}
	m=0;
	s=0;
	for (i=130000;i>=1;i--)
	if (ps[i]>0)
	{
		m++;
		t=m-ps[i];
		if (t<0) t=-t;
		s=gcd(s,t);
	}
	if (s==0)
	{
		printf("%d\n",n-1);
		return 0;
	}
	if (tag>s) s=tag;
	printf("%d\n",s-1);
	return 0;
}
