#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAXN 100011

long f[MAXN];
long d[MAXN];
long p[2][MAXN];
long ss[MAXN];
long r[MAXN];
long root;
long fre;
long n;

void zig(long pp)
{
	long ff,fff;
	ff=f[pp];
	fff=f[ff];
	ss[ff]-=ss[pp];
	p[0][ff]=p[1][pp];
	if(p[1][pp]>0) f[p[1][pp]]=ff;
	p[1][pp]=ff;
	f[ff]=pp;
	f[pp]=fff;
	if (p[0][fff]==ff)
		p[0][fff]=pp;
	else
		p[1][fff]=pp;
}

void zag(long pp)
{
	long ff,fff;
	ff=f[pp];
	fff=f[ff];
	ss[pp]+=ss[ff];
	p[1][ff]=p[0][pp];
	if(p[0][pp]>0) f[p[0][pp]]=ff;
	p[0][pp]=ff;
	f[ff]=pp;
	f[pp]=fff;
	if (p[0][fff]==ff)
		p[0][fff]=pp;
	else
		p[1][fff]=pp;
}

void turnup(long pp)
{
	if (f[pp]==0) return;
	if (r[pp]>=r[f[pp]]) return;
	if (p[0][f[pp]]==pp)
	{
		zig(pp);
		turnup(pp);
		return;
	}
	else
	{
		zag(pp);
		turnup(pp);
		return;
	}
}

void tz(long pp)
{
	r[pp]=rand();
	turnup(pp);
}

long fd(long a,long pp)
{
	if (pp==0) return 0;
	if (a+ss[pp]>d[pp]) return ss[pp]+fd(a+ss[pp],p[1][pp]);
	else return fd(a,p[0][pp]);
}

long inst(long dat,long pp,long b)
{
	long s;
	s=0;
	if (p[b][pp]==0)
	{
		fre++;
		p[b][pp]=fre;
		f[fre]=pp;
		d[fre]=dat;
		ss[fre]=1;
/*		tz(fre);*/
		return 0;
	}
	pp=p[b][pp];
	if (dat<d[pp])
	{
		ss[pp]++;
		s+=inst(dat,pp,0);
	}
	else
		s+=(inst(dat,pp,1)+ss[pp]);
	return s;
}

int main()
{
	long i,m,ret;
	char c1,c2;
	scanf("%d%d",&m,&n);
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	memset(p,0,sizeof(p));
	memset(ss,0,sizeof(ss));
	memset(r,0,sizeof(r));
	fre=0;
	for (i=1;i<=n;i++)
	{
		scanf("%c%c %d",&c1,&c2,&m);
		ret=fd(m,1);
		if (c2=='L') 
			printf("%d\n",ret+m);
		else
			inst(m+ret,0,1);
	}
	return 0;
}
