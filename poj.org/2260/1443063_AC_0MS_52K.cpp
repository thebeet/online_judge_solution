#include <stdio.h>
#include <memory.h>

long r[105];
long l[105];

int main()
{
	long i,j,n,m;
	scanf("%d",&n);
	while (n>0)
	{
		memset(r,0,sizeof(r));
		memset(l,0,sizeof(l));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
			{
				scanf("%d",&m);
				r[i]=r[i]+m;
				l[j]=l[j]+m;
			}
		for (i=1;i<=n;i++)
		{
			if ((r[i]%2)==1)
			{
				if (r[0]==0) r[0]=i;
				else 
				{
					r[0]=-1;
					break;
				};
			};
			if ((l[i]%2)==1)
			{
				if (l[0]==0) l[0]=i;
				else 
				{
					l[0]=-1;
					break;
				};
			};
		}
		if ((r[0]==0) && (l[0]==0))
		{
			printf("OK\n");
			scanf("%d",&n);
			continue;
		}
		if ((r[0]==-1) || (l[0]==-1))
		{
			printf("Corrupt\n");
			scanf("%d",&n);
			continue;
		}
		printf("Change bit (%d,%d)\n",r[0],l[0]);
		scanf("%d",&n);
	}
	return 0;
}
