#include <stdio.h>
#include <memory.h>

char map[25][25];
char mapbak[25][25];
bool dis[25][25];
long ans;
long n,m;

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long dfs(long x,long y,char map[25][25])
{
	char mapbak[25][25];
	long s;
	s=0;
	if ((x<n-1) && (y>2) && (map[x+1][y-1]==2) && (map[x+2][y-2]==0))
	{
		memcpy(mapbak,map,sizeof(mapbak));
		mapbak[x+1][y-1]=0;
		s=mx(s,dfs(x+2,y-2,mapbak)+1);
	}
	if ((x<n-1) && (y<m-1) && (map[x+1][y+1]==2) && (map[x+2][y+2]==0))
	{
		memcpy(mapbak,map,sizeof(mapbak));
		mapbak[x+1][y+1]=0;
		s=mx(s,dfs(x+2,y+2,mapbak)+1);
	}
	if ((x>2) && (y>2) && (map[x-1][y-1]==2) && (map[x-2][y-2]==0))
	{
		memcpy(mapbak,map,sizeof(mapbak));
		mapbak[x-1][y-1]=0;
		s=mx(s,dfs(x-2,y-2,mapbak)+1);
	}
	if ((x>2) && (y<m-1) && (map[x-1][y+1]==2) && (map[x-2][y+2]==0))
	{
		memcpy(mapbak,map,sizeof(mapbak));
		mapbak[x-1][y+1]=0;
		s=mx(s,dfs(x-2,y+2,mapbak)+1);
	}
	return s;
}

int main()
{
	long i,j;
	scanf("%ld%ld",&n,&m);
	while (n>0)
	{
		memset(map,3,sizeof(map));
		ans=0;
		for (i=1;i<=n;i++)
		{
			if ((i&1)==1)
			{
				for (j=1;j<=m;j+=2)
				{
					scanf("%d",&map[i][j]);
				}
			}
			else
			{
				for (j=2;j<=m;j+=2)
				{
					scanf("%d",&map[i][j]);
				}
			}
		}
		for (i=1;i<=n;i++)
			if ((i&1)==1)
			{
				for (j=1;j<=m;j+=2)
				{
					if (map[i][j]==1) 
					{
						memcpy(mapbak,map,sizeof(map));
						mapbak[i][j]=0;
						ans=mx(ans,dfs(i,j,mapbak));
					}
				}
			}
			else
			{
				for (j=2;j<=m;j+=2)
				{
					if (map[i][j]==1) 
					{
						memcpy(mapbak,map,sizeof(map));
						mapbak[i][j]=0;
						ans=mx(ans,dfs(i,j,mapbak));
					}
				}
			}
		printf("%ld\n",ans);
		scanf("%ld%ld",&n,&m);
	}
	return 0;
}

	
