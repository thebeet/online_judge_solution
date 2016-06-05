#include <stdio.h>

long t[111][4];
long ap[111][111];
long a[111];
long dp[111][111];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long d(long p,long s)
{
	long i,j,k,pt,m;
	if (p==0) return 0;
	if (s==0) return 0;
	if (s==1) return a[p];
	if (dp[p][s]>0) return dp[p][s];
	for (i=1;i<=t[p][0];i++)
	{
		pt=t[p][i];
		a[pt]=ap[p][pt];
		for (j=1;j<=t[pt][0];j++)
			if (t[pt][j]==p)
			{
				for (k=j;k<t[pt][0];k++)
					t[pt][k]=t[pt][k+1];
				t[pt][t[pt][0]]=0;
				t[pt][0]--;
				break;
			}
	}
	m=0;
	for (i=0;i<s;i++)
		m=mx(m,a[p]+d(t[p][1],i)+d(t[p][2],s-i-1));
	dp[p][s]=m;
	return m;
}

int main()
{
	long i,n,s,b1,b2,a;
	scanf("%d%d",&n,&s);
	for (i=1;i<n;i++)
	{
		scanf("%d%d%d",&b1,&b2,&a);
		ap[b1][b2]=a;
		ap[b2][b1]=a;
		t[b1][0]++;
		t[b1][t[b1][0]]=b2;
		t[b2][0]++;
		t[b2][t[b2][0]]=b1;
	}
	printf("%d\n",d(1,s+1));
	return 0;
}



