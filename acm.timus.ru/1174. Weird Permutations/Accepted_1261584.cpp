#include <stdio.h>
#include <memory.h>

long p[102];
long ans[300];

void hp_mul_num(long n)
{
	long i;
	for (i=1;i<=ans[0];i++)
		ans[i]*=n;
	for (i=1;i<=ans[0];i++)
	{
		ans[i+1]+=(ans[i]/10);
		ans[i]%=10;
	}
	while (ans[ans[0]+1]>0)
	{
		ans[0]++;
		ans[ans[0]+1]+=(ans[ans[0]]/10);
		ans[ans[0]]%=10;
	}
}

void hp_dec_num(long n)
{
	long i,t;
	t=0;
	ans[1]-=n;
	i=1;
	while (ans[i]<0)
	{
		while (ans[i]<0)
		{
			ans[i]+=10;
			ans[i+1]--;
		}
		i++;
	}
	while ((ans[ans[0]]==0) && (ans[0]>0))
		ans[0]--;
}

void out_hp()
{
	long i;
	for (i=ans[0];i>=1;i--)
		printf("%d",ans[i]);
	printf("\n");
}

int main()
{
	long i,j,n,m;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m);
		p[m]=i;
	}
	for (i=n;i>=2;i--)
		for (j=1;j<i;j++)
			if (p[j]>p[i])
				p[j]--;
	memset(ans,0,sizeof(ans));
	ans[0]=1;
	ans[1]=1;
	for (i=2;i<=n;i++)
		if ((ans[1]%2)==1)
		{
			hp_mul_num(i);
			hp_dec_num(p[i]-1);
		}
		else
		{
			hp_mul_num(i);
			hp_dec_num(i-p[i]);
		}
	out_hp();
	return 0;
}
	

	