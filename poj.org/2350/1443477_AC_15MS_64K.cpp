#include <stdio.h>

long a[1005];

int main()
{
	long ti,tn,i,n,s,m;
	double p;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d",&n);
		s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		m=0;
		for (i=1;i<=n;i++)
			if (s<a[i]*n) m++;
		p=m*0.1/n*1000;
		printf("%.3f%c\n",p,37);
	}
	return 0;
}
