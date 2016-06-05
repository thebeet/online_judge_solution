#include <stdio.h>
#include <memory.h>

long map[501][501];
long dl[2][501];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,j,k,n,m,f,t,c,p,px;
	scanf("%d%d",&n,&m);
	memset(map,0,sizeof(map));
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&f,&t,&c);
		map[f][t]=c;
	}
	scanf("%d%d",&f,&t);
	p=0;
	px=1;
	dl[0][0]=0;
	for (j=1;j<=n;j++)
		if (map[f][j]>0)
		{
			dl[0][0]++;
			dl[0][dl[0][0]]=j;
		}
	while (dl[p][0]>0)
	{
		memset(dl[px],0,sizeof(dl[px]));
		for (i=1;i<=dl[p][0];i++)
		{
			for (j=1;j<=n;j++)
				if (map[dl[p][i]][j]>0)
				{
					if (map[f][j]<map[f][dl[p][i]]+map[dl[p][i]][j])
					{
						dl[px][0]++;
						dl[px][dl[px][0]]=j;
						map[f][j]=map[f][dl[p][i]]+map[dl[p][i]][j];
					}
				}
		}
		p=p^1;
		px=px^1;
	}
	if (map[f][t]>0) printf("%d\n",map[f][t]);
	else printf("No solution\n");
	return 0;
}
				


