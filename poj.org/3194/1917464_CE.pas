#include <stdio.h>
#include <memory.h>

long map[110][110];
bool gone[110];
long n;

long floodfill(long x,long y)
{
	long t,s;
	s=1;
	t=map[x][y];
	map[x][y]=n;
	if (map[x-1][y]==t)
	{
		s+=floodfill(x-1,y);
	}
	if (map[x][y+1]==t)
	{
		s+=floodfill(x,y+1);
	}
	if (map[x+1][y]==t)
	{
		s+=floodfill(x+1,y);
	}
	if (map[x][y-1]==t)
	{
		s+=floodfill(x,y-1);
	}
	return s;
}	

int main()
{
	long i,j,x,y;
	bool ans;
	scanf("%ld",&n);
	while (n>0)
	{
		memset(map,1,sizeof(map));
		memset(gone,false,sizeof(gone));
		for (i=1;i<n;i++)
		{
			for (j=1;j<=n;j++)
			{
				scanf("%ld%ld",&x,&y);
				map[x][y]=i;
			}
		}
		ans=true;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (map[i][j]<n)
				{
					if (gone[map[i][j]])
					{
						ans=false;
					}
					else
					{
						gone[map[i][j]]=true;
						if (floodfill(i,j)!=n) ans=false;
					}
					if (ans==false) break;
				}
			}
			if (ans==false) break;
		}
		if (ans)
		{
			printf("good\n");
		}
		else
		{
			printf("wrong\n");
		}
		scanf("%ld",&n);			
	}
	return 0;
}	
