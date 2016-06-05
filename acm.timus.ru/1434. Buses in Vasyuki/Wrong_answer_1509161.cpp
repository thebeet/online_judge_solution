#include <stdio.h>
#include <memory.h>

long h[1010];
long d[200010];
long hh[100010];
long td[500010];
long p[500010];
bool gone[100010];
bool rgone[1010];
long pr[100010];
long dl[100010];
long ans[100010];
long n;
long fre;

void add_line(long a,long b)
{
	long pp;
	fre++;
	pp=hh[a];
	hh[a]=fre;
	td[fre]=b;
	p[fre]=pp;
}

int main()
{
	long i,j,n,m,l,k,f,t,dd,pp,tt;
	fre=0;
	memset(h,0,sizeof(h));
	memset(hh,0,sizeof(hh));
	memset(p,0,sizeof(p));
	memset(d,0,sizeof(d));
	memset(td,0,sizeof(td));
	memset(gone,false,sizeof(gone));
	memset(rgone,false,sizeof(rgone));
	memset(pr,0,sizeof(pr));
	memset(dl,0,sizeof(dl));
	memset(ans,0,sizeof(ans));
	scanf("%ld%ld",&n,&m);
	k=0;
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&l);
		h[i]=k+1;
		for (j=1;j<=l;j++)
		{
			k++;
			scanf("%ld",&d[k]);
			add_line(d[k],i);
		}
	}
	h[n+1]=k+1;
	scanf("%ld%ld",&f,&t);
	gone[f]=true;
	dl[0]=1;
	dd=0;
	dl[1]=f;
	while ((gone[t]==false) && (dd<dl[0]))
	{
		dd++;
		tt=dl[dd];
		pp=hh[tt];
		while (pp!=0)
		{
			if (rgone[td[pp]]==false)
			{
				rgone[td[pp]]=true;
				for (i=h[td[pp]];i<h[td[pp]+1];i++)
				{
					if (gone[d[i]]==false)
					{
						pr[d[i]]=tt;
						dl[0]++;
						dl[dl[0]]=d[i];
						gone[d[i]]=true;
					}
				}
			}
			pp=p[pp];
		}
	}
	if (gone[t])
	{
		pp=t;
		while (pp!=f)
		{
			ans[0]++;
			ans[ans[0]]=pp;
			pp=pr[pp];
		}
		printf("%ld ",f);
		for (i=ans[0];i>=1;i--)
			printf("%ld ",ans[i]);
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
