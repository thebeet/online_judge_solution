#include <stdio.h>
#include <memory.h>

#define MAXN 252

long n;
bool m[MAXN][MAXN];

void swaph(long h1,long h2)
{
	long i;
	for (i=1;i<=n+1;i++)
		if (m[h1][i]^m[h2][i])
		{
			m[h1][i]=!m[h1][i];
			m[h2][i]=!m[h2][i];
		}
}

void addh(long h1,long h2)
{
	long i;
	for (i=1;i<=n+1;i++)
		m[h2][i]^=m[h1][i];
}

int main()
{
	long i,j,l;
	scanf("%d",&n);
	memset(m,false,sizeof(m));
	for (i=1;i<=n;i++)
	{
		scanf("%d",&l);
		while (l>0)
		{
			m[l][i]=true;
			scanf("%d",&l);
		}
		m[i][n+1]=true;
	}
	for (i=1;i<=n;i++)
	{
		for (j=i;j<=n;j++)
			if (m[j][i]) break;
		swaph(j,i);
		for (j=i+1;j<=n;j++)
			if (m[j][i]) addh(i,j);
	}
	for (i=n;i>1;i--)
	{
		for (j=1;j<i;j++)
			if (m[j][i]) addh(i,j);
	}
	for (i=1;i<=n;i++)
		if (m[i][n+1]) printf("%d ",i);
	return 0;
}



