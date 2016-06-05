#include <stdio.h>
#include <memory.h>

bool dp[42][1010];
bool u[42][1010];
bool d[42][1010];
char ans[42];
long aa[42];
long n;

bool check(long h)
{
	long i,j,s;
	memset(dp,false,sizeof(dp));
	memset(u,false,sizeof(u));
	memset(d,false,sizeof(d));
	dp[0][0]=true;
	s=0;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=s;j++)
			if (dp[i-1][j])
			{
				dp[i][j+aa[i]]=true;
				u[i][j+aa[i]]=true;
				if (j>=aa[i])
				{
					dp[i][j-aa[i]]=true;
					d[i][j-aa[i]]=true;
				}
			}
		s+=aa[i];
		if (s>h) s=h;
	}
	return dp[n][0];
}

int main()
{
	long ti,tn,i,m,s,a,b;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d",&n);
		s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&aa[i]);
			s+=aa[i];
		}
		if (((s&1)==1) || (check(s>>1)==false))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		a=0;
		b=s>>1;
		while (a+1<b)
		{
			m=(a+b)>>1;
			if (check(m))
				b=m;
			else
				a=m;
		}
		check(b);
		memset(ans,0,sizeof(ans));
		m=0;
		for (i=n;i>0;i--)
			if (u[i][m])
			{
				ans[i]='U';
				m-=aa[i];
			}
			else
			{
				ans[i]='D';
				m+=aa[i];
			}
		for (i=1;i<=n;i++)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}
