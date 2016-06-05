#include <stdio.h>

__int64 gcd(__int64 a,__int64 b)
{
	__int64 r;
	if (a<b)
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
	__int64 ti,tn,i,n,m,s,g;
	scanf("%I64d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		s=1;
		scanf("%I64d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%I64d",&m);
			if (s>1000000000) continue;
			g=gcd(s,m);
			s=s*m/g;
		}
		if (s>1000000000) 
			printf("More than a billion.\n");
		else
			printf("%I64d\n",s);
	}
	return 0;
}
