#include <stdio.h>
#include <memory.h>

char s[200];
long dp[200][200];
long dpp[200][200];

void out(long l,long r)
{
	if (l>r) return;
	if (dpp[l][r]==-1)
	{
		if (s[l]=='[')
		{
			printf("[]");
			out(l+1,r);
		}
		if (s[l]=='(')
		{
			printf("()");
			out(l+1,r);
		}
		return;
	}
	if (dpp[l][r]==-2)
	{
		if (s[r]==')')
		{
			out(l,r-1);
			printf("()");
		}
		if (s[r]==']')
		{
			out(l,r-1);
			printf("[]");
		}
		return;
	}
	if (dpp[l][r]==-3)
	{
		if (s[l]=='[')
		{
			printf("[");
			out(l+1,r-1);
			printf("]");
		}
		if (s[l]=='(')
		{
			printf("(");
			out(l+1,r-1);
			printf(")");
		}
		return;
	}
	out(l,dpp[l][r]);
	out(dpp[l][r]+1,r);
}

int main()
{
	long i,j,k,n,e;
	memset(s,0,sizeof(s));
	memset(dp,0,sizeof(dp));
	memset(dpp,0,sizeof(dpp));
	scanf("%s",&s);
	n=0;
	while (s[n+1]>10)
		n++;
	for (i=0;i<=n;i++)
	{
		dp[i][i]=1;
		if ((s[i]=='[') || (s[i]=='('))
			dpp[i][i]=-1;
		else
			dpp[i][i]=-2;
	}
	for (i=1;i<=n;i++)
		for (j=0;j<=n-i;j++)
		{
			e=i+j;
			dp[j][e]=10000;
			if (((s[j]=='[') && (s[e]==']')) || ((s[j]=='(') && (s[e]==')')))
			{
				if (dp[j][e]>dp[j+1][e-1])
				{
					dp[j][e]=dp[j+1][e-1];
					dpp[j][e]=-3;
				}
			}
			if ((s[j]=='[') || (s[j]=='('))
			{
				if (dp[j][e]>dp[j+1][e]+1)
				{
					dp[j][e]=dp[j+1][e]+1;
					dpp[j][e]=-1;
				}
			}
			if ((s[e]==']') || (s[e]==')'))
			{
				if (dp[j][e]>dp[j][e-1]+1)
				{
					dp[j][e]=dp[j][e-1]+1;
					dpp[j][e]=-2;
				}
			}
			for (k=j;k<e;k++)
			{
				if (dp[j][e]>dp[j][k]+dp[k+1][e])
				{
					dp[j][e]=dp[j][k]+dp[k+1][e];
					dpp[j][e]=k;
				}
			}
		}
	out(0,n);
	printf("\n");
	return 0;
}




	
	