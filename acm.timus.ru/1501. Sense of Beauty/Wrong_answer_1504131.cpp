#include <stdio.h>
#include <memory.h>

char p[2][1010];
long s[2][1010];
bool map[1010][1010];
char path[1010][1010];
long ans[10000];
long n;

int main()
{
	long i,j,ti,x,y;
	memset(p,0,sizeof(p));
	memset(s,0,sizeof(s));
	memset(map,false,sizeof(map));
	memset(path,0,sizeof(path));
	scanf("%ld",&n);
	scanf("%s",p[0]+1);
	scanf("%s",p[1]+1);
	for (i=1;i<=n;i++)
	{
		s[0][i]=s[0][i-1]+p[0][i]-48;
		s[1][i]=s[1][i-1]+p[0][i]-48;
	}
	for (i=0;i<=n;i++)
		for (j=0;j<=n;j++)
			if (((s[0][i]-s[1][j])<=1) && ((s[0][i]-s[1][j])>=-1))
			 map[i][j]=true;
	path[0][0]=10;
	for (i=1;i<=n;i++)
	{
		ti=-1;
		for (j=i;j>=0;j--)
		{
			ti++;
			if (map[ti][j]==false) continue;
			if (path[ti-1][j]!=0) path[ti][j]=2;
			if (path[ti][j-1]!=0) path[ti][j]=1;
		}
	}
	for (i=1;i<=n;i++)
	{
		ti=i-1;
		for (j=n;j>=i;j--)
		{
			ti++;
			if (map[ti][j]==false) continue;
			if (path[ti-1][j]!=0) path[ti][j]=2;
			if (path[ti][j-1]!=0) path[ti][j]=1;
		}
	}
	if (path[n][n]==0)
	{
		printf("Impossible\n");
	}
	else
	{
		memset(ans,0,sizeof(ans));
		x=n;y=n;
		while (path[x][y]!=10)
		{
			ans[0]++;
			ans[ans[0]]=path[x][y];
			if (path[x][y]==2) x--;
			else y--;
		}
		for (i=n+n;i>=1;i--)
			printf("%ld",ans[i]);
		printf("\n");
	}
	return 0;
}
