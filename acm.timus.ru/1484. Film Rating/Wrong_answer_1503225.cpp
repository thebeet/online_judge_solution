#include <stdio.h>

int main()
{
	double dx,dy;
	long n,x,y,ans;
	scanf("%lf%lf",&dx,&dy);
	x=long(dx*100+0.1)+5;
	y=long(dy*100+0.1)+5;
	scanf("%ld",&n);
	if (x<=y)
	{
		printf("%d",0);
		return 0;
	}
	ans=n*(x-y)/(y-100);
	while ((ans*(y-100))<(n*(x-y)))
		ans++;
	printf("%ld\n",ans);
	return 0;
}
