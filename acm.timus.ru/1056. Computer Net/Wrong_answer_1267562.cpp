#include <stdio.h>
#include <memory.h>

#define MAXN 10001
long f[MAXN];
long b[MAXN];
long c[MAXN];
long dl[2][MAXN];
bool g[MAXN];
long p[MAXN];

int main()
{
	long i,n,t,d1,d2,bt,bg,be,pp,nn;
	scanf("%d",&n);
	for (i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);
		c[i]=0;
		b[i]=0;
		if (c[f[i]]==0)
			c[f[i]]=i;
		else
		{
			t=c[f[i]];
			while (b[t]>0)
				t=b[t];
			b[t]=i;
		}
	}
	dl[0][0]=1;
	dl[0][1]=1;
	d1=0;
	d2=1;
	memset(g,false,sizeof(g));
	g[0]=true;
	g[1]=true;
	while (dl[d1][0]>0)
	{
		memset(dl[d2],0,sizeof(dl[d2]));
		for (i=1;i<=dl[d1][0];i++)
		{
			t=dl[d1][i];
			if (g[f[t]]==false)
			{
				g[f[t]]=true;
				dl[d2][0]++;
				dl[d2][dl[d2][0]]=f[t];
			}
			bt=c[t];
			while (bt>0)
			{
				if (g[bt]==false)
				{
					g[bt]=true;
					dl[d2][0]++;
					dl[d2][dl[d2][0]]=bt;
				}
				bt=b[bt];
			}
		}
		d1^=1;
		d2^=1;
	}
	bg=dl[d2][1];
	dl[0][0]=1;
