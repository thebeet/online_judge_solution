#include <stdio.h>
#include <memory.h>

#define MAXN 50010

long f[MAXN];
long c[MAXN];
long b[MAXN];
long l[MAXN];
long s[MAXN];
long ans[MAXN];

long h[MAXN];
long p[100010];
long d[100010];
long dc[1000010];
long n;
long fre;

void add_line(long a,long b,long c)
{
	long pp;
	fre++;
	pp=h[a];
	h[a]=fre;
	d[fre]=b;
	dc[fre]=c;
	p[fre]=pp;
}
	
long maketree(long pp,long pr)
{
	long t,k,cc;
	s[pp]=1;
	t=h[pp];
	k=0;
	while (t!=0)
	{
		if (d[t]!=pr)
		{
			k++;
			if (k==1)
			{
				c[pp]=d[t];
				cc=c[pp];
				f[d[t]]=pp;
				l[d[t]]=dc[t];
				s[pp]+=maketree(d[t],pp);
			}
			else
			{
				b[cc]=d[t];
				f[d[t]]=pp;
				l[d[t]]=dc[t];
				s[pp]+=maketree(d[t],pp);
			}
		}
		t=p[t];
	}
	return s[pp];
}

long dfs(long pp)
{
	long t;
	ans[pp]=0;
	t=c[pp];
	while (t!=0)
	{
		ans[pp]+=s[t]*l[t];
		ans[pp]+=dfs(t);
		t=b[t];
	}
	return ans[pp];
}

void dfs_2(long pp)
{
	long t;
	if (pp!=1)
	{
		ans[pp]=ans[f[pp]]+(n-s[pp]-s[pp])*l[pp];
	}
	t=c[pp];
	while (t!=0)
	{
		dfs_2(t);
		t=b[t];
	}
	return;
}

int main()
{
	long i,a1,b1,c1,aa;
	double dans;
	scanf("%ld",&n);
	memset(h,0,sizeof(h));
	memset(p,0,sizeof(p));
	memset(d,0,sizeof(d));
	memset(dc,0,sizeof(dc));
	for (i=2;i<=n;i++)
	{
		scanf("%ld%ld%ld",&a1,&b1,&c1);
		add_line(a1,b1,c1);
		add_line(b1,a1,c1);
	}
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(l,0,sizeof(l));
	memset(s,0,sizeof(s));
	memset(ans,0,sizeof(ans));
	maketree(1,0);
	dfs(1);
	dfs_2(1);
	aa=0;
	for (i=1;i<=n;i++)
		aa+=ans[i];
	dans=aa*1.0/(n*(n-1));
	printf("%.10lf\n",dans);
	return 0;
}
