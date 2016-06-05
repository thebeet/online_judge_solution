#include <stdio.h>
#include <math.h>

int main()
{
	double dx,dy;
	long n,x,y,ans,t1,t2;
	scanf("%lf%lf",&dx,&dy);
	scanf("%ld",&n);
	x=long(dx*100+0.1)+5;
	dx=long((x*n-1)/100)*1.0/n;
	if (dx>10.0) dx=10.0;
	y=long(dy*100+0.1)+5;
	dy+=0.05;
	if (x<=y)
	{
		printf("%d",0);
		return 0;
	}
	ans=long(ceil(n*(dx-dy)/(dy-1))+0.1);
	t1=x*n+100*ans;
	t2=y*(n+ans);
	printf("%ld\n",ans);
	return 0;
}
