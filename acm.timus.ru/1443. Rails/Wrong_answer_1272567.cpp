#include <stdio.h>
#include <math.h>

int main()
{
	double a,s,l;
	long ans;
	scanf("%lf%lf%lf",&a,&s,&l);
	ans=long(ceil(a*s/l-0.000000001));
	printf("%d\n",ans);
	return 0;
}
