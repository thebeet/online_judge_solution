#include <stdio.h>
#include <memory.h>

long h[100010];
long p[500010];
long d[500010];
bool gone[100010];
long pr[100010];
long dl[100010];
long ans[100010];
long n;
long fre;

void add_line(long a,long b)
{
	long pp;
	fre++;
	pp=h[a];
	h[a]=fre;
	d[fre]=b;
	p[fre]=pp;
}

int main()
{
	long i,j,n,m,l,f,t,dd,pp,tt;
	fre=0;
	memset(h,0,sizeof(h));
	memset(p,0,sizeof(p));
	memset(d,0,sizeof(d));
	memset(gone,false,sizeof(gone));
	memset(pr,0,sizeof(pr));
	memset(dl,0,sizeof(dl));
	memset(ans,0,sizeof(ans));
	scanf("%ld%ld",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&l);
		scanf("%ld",&f);
		for (j=2;j<=l;j++)
		{
			scanf("%ld",&t);
			add_line(f,t);
			add_line(t,f);
			f=t;
		}
	}
	scanf("%ld%ld",&f,&t);
	gone[f]=true;
	dl[0]=1;
	dd=0;
	dl[1]=f;
	while ((gone[t]==false) && (dd<dl[0]))
	{
		dd++;
		tt=dl[dd];
		pp=h[tt];
		while (pp!=0)
		{
			if (gone[d[pp]]==false)
			{
				gone[d[pp]]=true;
				pr[d[pp]]=tt;
				dl[0]++;
				dl[dl[0]]=d[pp];
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
