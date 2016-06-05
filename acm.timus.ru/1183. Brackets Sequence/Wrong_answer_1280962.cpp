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
	if (dpp[l][r]==0)
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
		dpp[i][i]=-1;