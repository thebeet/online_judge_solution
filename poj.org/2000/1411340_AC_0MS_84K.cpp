#include <stdio.h>
int main()
{
	long i,n,a,b,m,mt;
	long ans[10001];
	ans[0]=0;
	m=0;mt=0;
	for (i=1;i<10001;i++)
	{
		if (mt<=0) mt=++m;
		ans[i]=ans[i-1]+m;
		mt--;
	}
	scanf("%d",&n);
	while (n>0)
	{
		printf("%d %d\n",n,ans[n]);
		scanf("%d",&n);
	}
	return 0;
}

