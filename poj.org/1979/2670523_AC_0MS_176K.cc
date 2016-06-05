#include <stdio.h>
#include <string.h>

char map[32][32];
long s;

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
	long i,j,n,m;
	while (scanf("%ld%ld",&m,&n), m > 0)
	{
		memset(map, '#', sizeof(map));
		s=0;
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
		printf("%ld\n",s);
	}
	return 0;
}

