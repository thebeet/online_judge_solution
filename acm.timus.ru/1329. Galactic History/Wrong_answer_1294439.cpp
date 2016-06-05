#include <stdio.h>
#include <memory.h>

#define MAXN 40010

long f[MAXN];
long c[MAXN];
long b[MAXN];
long h[MAXN];
long r[MAXN];
long l[80020];
long st[MAXN];
long mm[140000];
long root;
long n;

/*
void bfs(long p)
{
	long t;
	if (c[p]==0) return;
	h[c[p]]=h[p]+1;
	dl[0]++;
	dl[dl[0]]=c[p];
	t=b[c[p]];
	while (t>0)
	{
		h[t]=h[c[p]];
		dl[0]++;
		dl[dl[0]]=t;
		t=b[t];
	}
}

long lca(long p1,long p2)
{
	long t;
	if (h[p1]>h[p2])
	{
		t=p1;
		p1=p2;
		p2=t;
	}
	if (lc[p1][p2]>0) return lc[p1][p2];
	if (p1==p2)
		return p1;
	lc[p1][f[p2]]=lca(p1,f[p2]);
	return lc[p1][f[p2]];
}
*/
void dfs(long p)
{
	long t;
	l[0]++;
	l[l[0]]=p;
	r[p]=l[0];
	if (c[p]!=0)
	{
		h[c[p]]=h[p]+1;
		dfs(c[p]);
		l[0]++;
		l[l[0]]=p;
		t=b[c[p]];
		while (t!=0)
		{
			h[t]=h[c[p]];
			dfs(t);
			l[0]++;
			l[l[0]]=p;
			t=b[t];
		}
	}
}

void rmq()
{
	long i,pt1,pt2;
	h[0]=1000000000;
	for (i=1;i<=l[0];i++)
		mm[i+65535]=l[i];
	for (i=65535;i>=1;i--)
	{
		pt1=i<<1;
		pt2=pt1+1;
		if (h[mm[pt1]]<h[mm[pt2]])
			mm[i]=mm[pt1];
		else
			mm[i]=mm[pt2];
	}
}

long query(long qp,long qh,long ql,long qr)
{
	long wl,wm,wr,retl,retr,pt1,pt2;
	wl=qp<<qh;
	wr=(qp+1)<<qh;
	wm=(wl+wr)>>1;
	wr--;
	if ((ql==wl) && (qr==wr)) return mm[qp];
	qh--;
	pt1=qp<<1;
	pt2=pt1+1;
	if (qr<wm) return query(pt1,qh,ql,qr);
	if (ql>=wm) return query(pt2,qh,ql,qr);
	retl=query(pt1,qh,ql,wm-1);
	retr=query(pt2,qh,wm,qr);
	if (h[retl]<h[retr]) 
		return retl;
	else
		return retr;
}

int main()
{
	long i,j,m,t,p1,p2,ret;
	scanf("%d",&n);
	/* init*/
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	memset(h,0,sizeof(h));
	memset(r,0,sizeof(r));
	memset(l,0,sizeof(l));
	memset(mm,0,sizeof(mm));
	/* input (left child right brother)*/
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&p1,&p2);
		f[p1]=p2;
		if (p2==-1)
			root=p1;
		else
		{
			if (c[p2]==0)
			{
				c[p2]=p1;
			}
			else
			{
				t=c[p2];
				while (b[t]>0)
					t=b[t];
				b[t]=p1;
			}
		}
	}
	/* dfs */
	h[root]=1;
	dfs(root);
	rmq();
	/* query */
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&p1,&p2);
		if (r[p1]<r[p2])
			ret=query(1,16,r[p1]+65535,r[p2]+65535);
		else
			ret=query(1,16,r[p2]+65535,r[p1]+65535);
		if (ret==p1)
			printf("1\n");
		else
		{
			if (ret==p2) 
				printf("2\n");
			else
				printf("0\n");
		}
	}
	return 0;
}
