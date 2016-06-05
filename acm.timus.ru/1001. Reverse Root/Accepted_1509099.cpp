#include <stdio.h>
#include <math.h>

double ans[1000000];

int main()
{
//	freopen("Reverse_root.in","r",stdin);
	long i,n;
	double d;
	n=0;
	while (scanf("%lf",&d)!=EOF)
	{
		n++;
		ans[n]=sqrt(d);
	}
	for (i=n;i>=1;i--)
		printf("%.4lf\n",ans[i]);
	return 0;
}
