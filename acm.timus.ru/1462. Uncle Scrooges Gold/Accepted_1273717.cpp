#include <stdio.h>
#include <memory.h>

#define w 100000

__int64 hp[4][20000];
__int64 bin[30];

void eq(__int64 n1,__int64 n2)
{
	__int64 i;
	for (i=0;i<=hp[n2][0];i++)
		hp[n1][i]=hp[n2][i];
}

void sqr(__int64 n)
{
	__int64 i,j;
	memset(hp[0],0,sizeof(hp[0]));
	for (i=1;i<=hp[n][0];i++)
		for (j=1;j<=hp[n][0];j++)
			hp[0][i+j-1]+=hp[n][i]*hp[n][j];
	hp[0][0]=hp[n][0]*2-1;
	for (i=1;i<=hp[0][0];i++)
	{
		hp[0][i+1]+=hp[0][i]/w;
		hp[0][i]%=w;
	}
	while (hp[0][hp[0][0]+1]>0)
	{
		hp[0][0]++;
		hp[0][hp[0][0]]+=hp[0][hp[0][0]-1]/w;
		hp[0][hp[0][0]-1]%=w;
	}
	eq(n,0);
}

void add(__int64 n1,__int64 n2)
{
	__int64 i,n;
	n=hp[n1][0];
	if (hp[n2][0]>hp[n1][0]) n=hp[n2][0];
	for (i=1;i<=n;i++)
	{
		hp[n1][i]+=hp[n2][i];
		hp[n1][i+1]+=hp[n1][i]/w;
		hp[n1][i]%=w;
	}
	hp[n1][0]=n;
	while (hp[n1][hp[n1][0]+1]>0)
	{
		hp[n1][0]++;
		hp[n1][hp[n1][0]]+=hp[n1][hp[n1][0]-1]/w;
		hp[n1][hp[n1][0]-1]%=w;
	}
}

void hdec()
{
	__int64 i;
	for (i=hp[3][0];i>0;i--)
	{
		hp[2][i]=hp[3][i]-hp[1][i];
		if (hp[2][i]<0)
		{
			hp[2][i]+=w;
			hp[2][i+1]-=1;
		}
	}
	hp[2][0]=hp[3][0];
	while (hp[2][hp[2][0]]==0)
		hp[2][0]--;
}

void out(__int64 n)
{
	__int64 i;
	printf("%d",hp[n][hp[n][0]]);
	for (i=hp[n][0]-1;i>0;i--)
	{
  		if (hp[n][i]<10) printf("%d",0);
		if (hp[n][i]<100) printf("%d",0);
		if (hp[n][i]<1000) printf("%d",0);
		if (hp[n][i]<10000) printf("%d",0);
		printf("%d",hp[n][i]);
	}
	printf("\n");
}

int main()
{
	__int64 i,n,nn;
	scanf("%I64d",&n);
	memset(hp,0,sizeof(hp));
	hp[2][0]=1;
	hp[2][1]=1;
	hp[3][0]=1;
	hp[3][1]=1;
	nn=0;
	while (n>0)
	{
		nn++;
		bin[nn]=n%2;
		n/=2;
	}
	for (i=nn-1;i>0;i--)
	{
		sqr(1);
		sqr(2);
		sqr(3);
		add(1,2);
		add(3,2);
		hdec();
		if (bin[i]==1)
		{
			eq(1,2);
			eq(2,3);
			add(3,1);
		}
	}
	add(3,1);
	out(3);
	return 0;
}

