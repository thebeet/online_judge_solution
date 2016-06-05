#include <stdio.h>
#include <memory.h>

#define MAXN 1010

bool ha[MAXN][MAXN];
long ht[MAXN][MAXN];
long hn[MAXN];

int main()
{
	long i,j,n,m,p,k1,k2;
	scanf("%d%d",&n,&m);
	while (n>0)
	{
		memset(ha,false,sizeof(ha));
		memset(ht,0,sizeof(ht));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&k1,&k2);
			if (ha[k1][k2]==false)
			{
				ha[k1][k2]=true;
				ha[k2][k1]=true;
				ht[k1][0]++;
				ht[k1][ht[k1][0]]=k2;
				ht[k2][0]++;
				ht[k2][ht[k2][0]]=k1;
			}
		}
		for (i=1;i<=n;i++)
			hn[i]=ht[i][0];
		for (i=1;i<=n;i++)
		{
			m=0;
			for (j=1;j<=n;j++)
				if (ht[j][0]>m)
				{
					m=ht[j][0];
					p=j;
				}
			if (m==0) break;
			for (j=1;j<=hn[p];j++)
				ht[ht[p][j]][0]--;
			ht[p][0]=0;
		}
		printf("%d\n",i-1);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
			
			
	