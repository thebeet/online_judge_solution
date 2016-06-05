#include <stdio.h>
#include <memory.h>

#define MAXN 50010

#define INT __int64

INT f[MAXN];
INT c[MAXN];
INT b[MAXN];
INT l[MAXN];
INT s[MAXN];
INT ans[MAXN];

INT h[MAXN];
INT p[100010];
INT d[100010];
INT dc[1000010];
INT n;
INT fre;

void add_line(INT a,INT b,INT c)
{
	INT pp;
	fre++;
	pp=h[a];
	h[a]=fre;
	d[fre]=b;
	dc[fre]=c;
	p[fre]=pp;
}
	
INT maketree(INT pp,INT pr)
{
	INT t,k,cc;
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

INT dfs(INT pp)
{
	INT t;
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

void dfs_2(INT pp)
{
	INT t;
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
	INT i,a1,b1,c1,aa;
	double dans;
	scanf("%I64d",&n);
	memset(h,0,sizeof(h));
	memset(p,0,sizeof(p));
	memset(d,0,sizeof(d));
	memset(dc,0,sizeof(dc));
	for (i=2;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&a1,&b1,&c1);
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
