#include <stdio.h>

int main()
{
	double dx,dy;
	__int64 n,x,y,ans;
	scanf("%lf%lf",&dx,&dy);
	x=__int64(dx*100+0.1);
	y=__int64(dy*100+0.1)+5;
	scanf("%I64d",&n);
	if (x<=y)
	{
		printf("%I64d\n",0);
		return 0;
	}
	ans=n*(x-y)/(y-100);
	if ((ans*(y-100))<=(n*(x-y)))
		ans++;
	printf("%I64d\n",ans);
	return 0;
}