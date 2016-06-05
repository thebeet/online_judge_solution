#include <stdio.h>

#define MAXN 101

long p[MAXN];
long id[MAXN];
long h[MAXN];
char cc[MAXN];
long hp[MAXN];
long dp[MAXN];
char c[MAXN];
long b[MAXN];
long e[MAXN];

void sort(long l,long r)
{
	long i,j,xl,y;
	char ct;
	i=l;j=r;
	xl=p[(i+j)/2];
	for (;;)
	{
		while (p[i]<xl)
			i++;
		while (p[j]>xl)
			j--;
		if (i<=j)
		{
			y=p[i];
			p[i]=p[j];
			p[j]=y;
			y=id[i];
			id[i]=id[j];
			id[j]=y;
			ct=c[i];
			c[i]=c[j];
			c[j]=ct;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

void turnup(long p)
{
	long t,pt;
	char ct;
	if (p<2) return;
	pt=p>>1;
	if (h[pt]<h[p])
	{
		t=dp[h[p]];
		dp[h[p]]=dp[h[pt]];
		dp[h[pt]]=t;
		ct=cc[p];
		cc[p]=cc[pt];
		cc[pt]=ct;
		t=h[p];
		h[p]=h[pt];
		h[pt]=t;
		turnup(pt);
	}
}

void turndown(long p)
{
	long t,pt,pt2;
	char ct;
	pt=p<<1;
	if (pt>h[0]) return;
	pt2=pt+1;
	if ((pt2<=h[0]) && (h[pt2]>h[pt])) pt=pt2;
	if (h[pt]>h[p])
	{
		t=dp[h[p]];
		dp[h[p]]=dp[h[pt]];
		dp[h[pt]]=t;
		ct=cc[p];
		cc[p]=cc[pt];
		cc[pt]=ct;
		t=h[p];
		h[p]=h[pt];
		h[pt]=t;
		turndown(pt);
	}
}

void inst(long id,char c)
{
	h[0]++;
	h[h[0]]=id;
	cc[h[0]]=c;
	dp[id]=h[0];
	turnup(h[0]);
}

void dell(long id)
{
	h[dp[id]]=h[h[0]];
	cc[dp[id]]=cc[h[0]];
	dp[h[h[0]]]=dp[id];
	h[0]--;
	turnup(dp[id]);
	turndown(dp[id]);
}

int main()
{
	long i,n,st,m,nn,pp,dx;
	scanf("%d",&n);
	n+=n;
	p[0]=0;
	p[1]=1000000000;
	id[0]=0;
	id[1]=1;
	c[0]='w';
	nn=0;
	dx=0;
	for (i=1;i<=n;i=i+2)
	{
		scanf("%d %d %c",&p[i+1-dx],&p[i+2-dx],&c[i+1-dx]);
		if (p[i+1-dx]==p[i+2-dx]) dx=dx+2;
		id[i-dx+1]=i+1-dx;
		id[i-dx+2]=i+2-dx;
	}
	n=n-dx;
	sort(0,n+1);
	m=0;
	st=0;
	nn=0;
	for (i=0;i<=n+1;i++)
	{
		if ((id[i]%2)==0)
			inst(id[i]/2,c[i]);
		else
			dell(id[i]/2);
		if (cc[1]=='b')
		{
			if (st==e[nn])
				e[nn]=p[i];
			else
			{
				nn++;
				b[nn]=st;
				e[nn]=p[i];
			}
			st=p[i+1];
		}
	}
	if (st==e[nn])
		e[nn]=1000000000;
	else
	{
		nn++;
		b[nn]=st;
		e[nn]=1000000000;
	}
	m=-1;
	for (i=0;i<=nn;i++)
		if (m<(e[i]-b[i]))
		{
			m=e[i]-b[i];
			pp=i;
		}
	printf("%d %d\n",b[pp],e[pp]);
	return 0;
}
	




