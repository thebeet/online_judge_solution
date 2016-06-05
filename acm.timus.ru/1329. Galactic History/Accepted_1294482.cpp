#pragma comment(linker, "/STACK:8388608")

#include <stdio.h>
#include <memory.h>

#define MAXN 40010
#define ppp 131071

long f[MAXN];
long c[MAXN];
long b[MAXN];
long h[MAXN];
long r[MAXN];
long l[80020];
long mm[270000];
long root;
long n;

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
		mm[i+ppp]=i+ppp;
	for (i=l[0]+ppp+1;i<=270000;i++)
		mm[i]=ppp;
	l[0]=0;
	for (i=ppp;i>=1;i--)
	{
		pt1=i<<1;
		pt2=pt1+1;
		if (h[l[mm[pt1]-ppp]]<h[l[mm[pt2]-ppp]])
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
	if ((ql<=mm[qp]) && (mm[qp]<=qr)) return l[mm[qp]-ppp];
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
	long i,m,t,p1,p2,ret;
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
		p1++;
		p2++;
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
		p1++;
		p2++;
		if (r[p1]<r[p2])
			ret=query(1,17,r[p1]+ppp,r[p2]+ppp);
		else
			ret=query(1,17,r[p2]+ppp,r[p1]+ppp);
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
