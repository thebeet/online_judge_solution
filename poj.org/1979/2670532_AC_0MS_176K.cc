#include <stdio.h>
#include <string.h>

char map[32][32];
int s;

void floodfill(long x,long y)
{
	++s;
	map[x][y]='#';
	if (map[x+1][y]=='.') floodfill(x+1,y);
	if (map[x][y+1]=='.') floodfill(x,y+1);
	if (map[x-1][y]=='.') floodfill(x-1,y);
	if (map[x][y - 1]=='.') floodfill(x,y - 1);
	return;
}

int main()
{
	int i,j,n,m;
	while (scanf("%d%d",&m,&n), ((m > 0) || (n > 0)))
	{
		memset(map, '#', sizeof(map));
		s = 0;
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
					floodfill(i,j);
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}

