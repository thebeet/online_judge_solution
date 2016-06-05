#include <stdio.h>
char map[200][200];
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	while (n>0)
	{
		m=1;
		scanf("%c",&map[0][0]);
		scanf("%c",&map[1][1]);
		for (i=1;;i++)
		{
			for (j=2;j<=n;j++)
				scanf("%c",&map[i][j]);
			scanf("%c",&map[i+1][n]);
			if (map[i+1][n]<20) break;
			m++;
			i++;
			for (j=n-1;j>=1;j--)
				scanf("%c",&map[i][j]);
			scanf("%c",&map[i+1][1]);
			if (map[i+1][1]<20) break;
			m++;
		}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				printf("%c",map[j][i]);
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}

