#include <stdio.h>
#include <memory.h>

long map[501][501];
bool dl[2][501];

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
	for (j=1;j<=n;j++)
		if (map[f][j]>0)
		{
			dl[0][0]=true;
			dl[0][j]=true;
		}
	while (dl[p][0])
	{
		memset(dl[px],false,sizeof(dl[px]));
		for (i=1;i<=n;i++)
			if (dl[p][i]>0)
			{
				for (j=1;j<=n;j++)
					if (map[i][j]>0)
					{
						if (map[f][j]<map[f][i]+map[i][j])
						{
							dl[px][0]=true;
							dl[px][j]=true;
							map[f][j]=map[f][i]+map[i][j];
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
				


