#include <stdio.h>
#include <memory.h>

#define d 1000000

long hp[10011][700];

void hp_double(long p1,long p2)
{
	long i;
	for (i=1;i<=hp[p1][0];i++)
		hp[p2][i]=hp[p1][i]+hp[p1][i];
	hp[p2][0]=hp[p1][0];
	for (i=1;i<=hp[p2][0];i++)
		if (hp[p2][i]>=d)
		{
			hp[p2][i]-=d;
			hp[p2][i+1]++;
		}
	while (hp[p2][hp[p2][0]+1]>0)
		hp[p2][0]++;
}

void hp_dec_hp(long p1,long p2)
{
	long i;
	for (i=1;i<=hp[p1][0];i++)
		hp[p1][i]-=hp[p2][i];
	for (i=1;i<=hp[p1][0];i++)
		if (hp[p1][i]<0)
		{
			hp[p1][i]+=d;
			hp[p1][i+1]--;
		}
	while (hp[p1][hp[p1][0]]==0)
		hp[p1][0]--;
}

void out(long p1)
{
	long i;
	printf("%d",hp[p1][hp[p1][0]]);
	for (i=hp[p1][0]-1;i>0;i--)
	{
		if (hp[p1][i]<100000) printf("0");
		if (hp[p1][i]<10000) printf("0");
		if (hp[p1][i]<1000) printf("0");
		if (hp[p1][i]<100) printf("0");
		if (hp[p1][i]<10) printf("0");
		printf("%d",hp[p1][i]);
	}
	printf("\n");
}

int main()
{
	long i,n,m,t;
	scanf("%d%d",&n,&m);
	memset(hp,0,sizeof(hp));
	hp[0][0]=1;
	hp[0][1]=1;
	t=0;
	for (i=1;i<=m+1;i++)
		hp_double(i-1,i);
	hp[m+1][1]--;
	for (i=m+2;i<=n;i++)
	{
		hp_double(i-1,i);
		hp_dec_hp(i,t);
		t++;
	}
	out(n);
	return 0;
}

