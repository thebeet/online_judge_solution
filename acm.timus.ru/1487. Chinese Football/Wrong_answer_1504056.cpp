#include <stdio.h>
#include <memory.h>

char win[1010][1010];
long wins[1010];
bool check[1010];
long n;

long findmin()
{
	long i;
	for (i=1;i<=n;i++)
		if ((check[i]==false) && (wins[i]==0)) return i;
	return 0;
}

int main()
{
	long i,j,h,m,a,b;
	scanf("%ld",&n);
	memset(win,0,sizeof(win));
	memset(wins,0,sizeof(wins));
	memset(check,false,sizeof(check));
	for (i=1;i<=n;i++)
	{
		scanf("%s",win[i]+1);
		for (j=1;j<=n;j++)
			wins[i]+=(win[i][j]-48);
	}
	for (j=1;j<=n;j++)
	{
		m=findmin();
		check[m]=true;
		for (i=1;i<=n;i++)
			if (win[i][m]=='1')
			{
				for (h=1;h<=n;h++)
					win[i][h]|=win[m][h];
				wins[i]--;
			}
	}
	scanf("%ld",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%ld%ld",&a,&b);
		if (win[a][b]=='1') printf("YES\n");
		else printf("No\n");
	}
	return 0;
}
