#include <stdio.h>
#include <memory.h>

__int64 g[10010];
__int64 f[10010];

int main()
{
	__int64 i,j,sg,n,p;
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	g[1]=1;
	sg=1;
	f[1]=1;
	scanf("%I64d%I64d",&n,&p);
	while (n>0)
	{
		for (i=2;i<=n;i++)
		{
			g[i]=(sg-g[i-1]*g[i-1])%p;
			sg=(sg+g[i-1]+g[i-1])%p;
			f[i]=(f[i-1]+f[i-1]*g[i-1])%p;
		}
		printf("%I64d\n",(f[n]+p)%p);
		scanf("%I64d%I64d",&n,&p);
	}
	return 0;
}
