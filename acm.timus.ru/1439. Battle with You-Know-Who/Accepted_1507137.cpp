#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAXN 10010

long l[MAXN],r[MAXN],s[MAXN],f[MAXN],d[MAXN],rks[MAXN];
long fre;

void init()
{
	fre=1;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(s,0,sizeof(s));
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	memset(rks,0,sizeof(rks));
	s[1]=1;
	rks[1]=-1000;
	return;
}

void turnup(long p)
{
	long pt,fpt;
	if (p==1) return;
	pt=f[p];
	if (rks[pt]>rks[p])
	{
		s[p]=s[pt];
		if (l[pt]==p)
		{
			l[pt]=r[p];
			if (r[p]!=0) f[r[p]]=pt;
			r[p]=pt;
			fpt=f[pt];
			f[pt]=p;
			if (l[fpt]==pt)
			{
				l[fpt]=p;
			}
			else
			{
				r[fpt]=p;
			}
			f[p]=fpt;
			s[pt]-=(s[l[p]]+1);
		}
		else
		{
			r[pt]=l[p];
			if (l[p]!=0) f[l[p]]=pt;
			l[p]=pt;
			fpt=f[pt];
			f[pt]=p;
			if (l[fpt]==pt)
			{
				l[fpt]=p;
			}
			else
			{
				r[fpt]=p;
			}
			f[p]=fpt;
			s[pt]-=(s[r[p]]+1);
		}
		turnup(pt);
	}		
	return;
}

void treap(long p)
{
	long rank;
	rank=long(rand()*1000);
	rks[p]=rank;
	turnup(p);
	return;
}

long finds(long p,long rs)
{
	long pt1,pt2;
	if (p==0) return rs;
	pt1=l[p];
	pt2=r[p];
	if (s[pt1]+rs<d[p])
	{
		return finds(pt1,rs);
	}
	else
	{
		return finds(pt2,s[pt1]+rs+1);
	}
}

void insert(long p,long dat)
{
	s[p]++;
	if (d[p]>dat)
	{
		if (l[p]!=0)
		{
			insert(l[p],dat);
			return;
		}
		else
		{
			l[p]=fre+1;
		}
	}
	else
	{
		if (r[p]!=0)
		{
			insert(r[p],dat);
			return;
		}
		else
		{
			r[p]=fre+1;
		}
	}
	fre++;
	f[fre]=p;
	d[fre]=dat;
	s[fre]=1;
	treap(fre);
	return;
}

int main()
{
	long i,n,m,p,ret;
	char op;
	init();
	scanf("%ld%ld",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%c",&op);
		scanf("%c %ld",&op,&p);
		ret=finds(1,p-1);
		if (op=='L')
		{
			printf("%ld\n",ret);
		}
		else
		{
			insert(1,ret);
		}
	}
	return 0;
}
