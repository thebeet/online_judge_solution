#include <stdio.h>
#include <memory.h>

long ans[10000010];

long i,n,m,p;

int main()
{
	scanf("%ld%ld",&n,&p);
	memset(ans,0,sizeof(ans));
	ans[1]=0;
	ans[2]=1;
	for (i=3;i<=n;i++)
	{
		ans[i]=(ans[i-1]+ans[i>>1])%p;
	}
	printf("%ld\n",ans[n]);
	return 0;
}

