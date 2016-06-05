#include <stdio.h>
#include <memory.h>

char map[110][110];

void floodfill(long x,long y)
{
	long i,j;
	map[x][y]='*';
	for (i=-1;i<=1;i++)
	{
		for (j=-1;j<=1;j++)
		{
			if (map[x+i][y+j]=='@') floodfill(x+i,y+j);
		}
	}
	return;
}

int main()
{
	long i,j,n,m,s;
	while (scanf("%ld%ld",&n,&m), n > 0)
	{
		s = 0;
		memset(map, '*', sizeof(map));
		for (i=1;i<=n;i++)
		{
			scanf("%s",map[i]+1);
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				if (map[i][j]=='@')
				{
					s++;
					floodfill(i,j);
				}
			}
		}
		printf("%ld\n",s);
	}
	return 0;
}
