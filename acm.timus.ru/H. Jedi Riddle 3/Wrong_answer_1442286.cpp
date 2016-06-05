#include <stdio.h>
#include <memory.h>

#define MAXN 150

__int64 e[MAXN][MAXN];
__int64 d[MAXN][MAXN];
__int64 t[MAXN][MAXN];
__int64 k[MAXN];
__int64 bin[MAXN];
__int64 n,y;

void d_M_d()
{
	__int64 i,j,k;
	memset(t,0,sizeof(t));
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			for (k=1;k<=n;k++)
				t[i][j]=(t[i][j]+(d[i][k]*d[k][j]))%y;
	memcpy(d,t,sizeof(d));
}

void d_M_e()
{
	__int64 i,j,k;
	memset(t,0,sizeof(t));
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			for (k=1;k<=n;k++)
				t[i][j]=(t[i][j]+(d[i][k]*e[k][j]))%y;
	memcpy(d,t,sizeof(d));
}

void out()
{
	__int64 i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			printf("%I64d ",e[i][j]);
		printf("\n");
	}
	return;
}

int main()
{
	__int64 i,j,x,m,s;
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	for (i=1;i<=n;i++)
		scanf("%I64d",&k[i]);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&e[i][n]);
		e[i][i-1]=1;
	}
	memset(bin,0,sizeof(bin));
	memset(d,0,sizeof(d));
	for (i=1;i<=n;i++)
		d[i][i]=1;
	x--;
	while (x>0)
	{
		d_M_d();
		if (x&1) d_M_e();
		x>>=1;
	}
	s=0;
	for (i=1;i<=n;i++)
		s=(s+(d[1][i]*k[i]))%y;
	printf("%I64d\n",s);
	return 0;
}
