#include <stdio.h>
#include <memory.h>

long map[501][501];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,j,k,n,m,f,t,c;
	memset(map,0,sizeof(map));
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&f,&t,&c);
		map[f][t]=c;
	}
	scanf("%d%d",&f,&t);
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if ((map[i][k]>0) && (map[k][j]>0)) map[i][j]=mx(map[i][j],map[i][k]+map[k][j]);
	printf("%d\n",map[f][t]);
	return 0;
}
