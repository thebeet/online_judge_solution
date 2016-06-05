#include <stdio.h>
#include <memory.h>

long pi[10010];

int main()
{
	long ti,tn,i,n,f,r,s;
	double a,b,m;
	scanf("%ld",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%ld%ld",&n,&f);
		f++;
		memset(pi,0,sizeof(pi));
		for (i=1;i<=n;i++)
		{
			scanf("%ld",&r);
			pi[i]=r*r;
		}
		a=0.00000001;
		b=1000000000;
		while (a+0.00000001<b)
		{
			m=(a+b)/2.0;
			s=0;
			for (i=1;i<=n;i++)
			{
				s+=long(pi[i]*1.0/m+0.0000000000001);
			}
			if (s>=f) a=m;
			else b=m;
		}
		printf("%.6lf\n",3.141592653589793*a);
	}
	return 0;
}
