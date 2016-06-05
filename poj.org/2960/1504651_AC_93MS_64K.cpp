#include <stdio.h>
#include <memory.h>

long nim[10001];
long s[102];
bool nimu[102];

int main()
{
	long i,j,n,l,m,t,w;
	scanf("%d",&n);
	while (n>0)
	{
		for (i=1;i<=n;i++)
			scanf("%d",&s[i]);
		nim[0]=0;
		for (i=1;i<=10000;i++)
		{
			memset(nimu,false,sizeof(nimu));
			for (j=1;j<=n;j++)
				if ((i-s[j])>=0)
					nimu[nim[i-s[j]]]=true;
			for (j=0;j<=101;j++)
				if (!nimu[j]) break;
			nim[i]=j;
		}
		scanf("%d",&m);
		for (i=1;i<=m;i++)
		{
			scanf("%d",&l);
			t=0;
			for (j=1;j<=l;j++)
			{
				scanf("%d",&w);
				t^=nim[w];
			}
			if (t) printf("W");
			else printf("L");
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
		


