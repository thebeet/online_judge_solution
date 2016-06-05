#include <stdio.h>
#include <memory.h>

char f[10110];
long hp[60010];
long n;

long dv2()
{
	long i;
	f[0]=0;
	for (i=n;i>0;i--)
	{
		f[i-1]=f[i-1]+(f[i]%2)*10;
		f[i]/=2;
	}
	while (f[n]==0)
		n--;
	return f[0]/10;
}

void mu2()
{
	long i;
	for (i=1;i<=hp[0];i++)
		hp[i]*=2;
	for (i=1;i<=hp[0];i++)
		if (hp[i]>9)
		{
			hp[i+1]=hp[i+1]+hp[i]/10;
			hp[i]%=10;
		}
	while (hp[hp[0]+1]>0)
		hp[0]++;
}

int main()
{
	long i,k;
	char t;
	n=1;
	memset(f,0,sizeof(f));
	memset(hp,0,sizeof(hp));
	scanf("%c",&f[n]);
	while (f[n]>30)
	{
		f[n]-=48;
		n++;
		scanf("%c",&f[n]);
	}
	n--;
	for (i=n;i>(n/2);i--)
	{
		t=f[i];
		f[i]=f[n+1-i];
		f[n+1-i]=t;
	}
	k=1;
	while ((n!=1) || (f[1]!=1))
		if (dv2()>0)
			k++;
	hp[0]=1;
	hp[1]=1;
	for (i=1;i<=k;i++)
		mu2();
	hp[1]--;
	for (i=hp[0];i>=1;i--)
		printf("%d",hp[i]);
	printf("\n");
	return 0;
}

