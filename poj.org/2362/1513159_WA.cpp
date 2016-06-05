#include <stdio.h>
#include <memory.h>

long st[30];
long s[30];
bool dp[200001];

int main()
{
	long ti,tn,i,j,n,m;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(dp,false,sizeof(dp));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		m=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&st[i]);
			s[i]=s[i-1]+st[i];
			if (m<st[i]) m=st[i];
		}
		if (((s[n]&3)!=0) || ((s[n]>>2)<m))
		{
			printf("no\n");
			continue;
		}
		m=s[n]>>2;
		dp[0]=true;
		for (i=1;i<=n;i++)
			for (j=s[i-1];j>=0;j--)
				if (dp[j]) dp[j+st[i]]=true;
		if (dp[m] && dp[m+m] && dp[m+m+m]) 
			printf("yes\n");
		else 
			printf("no\n");
	}
	return 0;
}

