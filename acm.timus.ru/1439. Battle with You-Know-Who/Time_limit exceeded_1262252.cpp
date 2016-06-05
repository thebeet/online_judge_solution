#include <stdio.h>
#include <memory.h>
#define mx 11000
long d[mx];
long m[mx];
long l[mx];
long r[mx];
long fre;

long fd(long a,long pp)
{
	if (pp==0) return 0;
	if (a+m[pp]>d[pp]) return m[pp]+fd(a+m[pp],r[pp]);
	else return fd(a,l[pp]);
}

long inst(long a,long pp,long ppp,long dl)
{
	if (pp==0)
	{
		fre++;
		if (dl==0) l[ppp]=fre;
		else r[ppp]=fre;
		d[fre]=a;
		m[fre]=1;
		l[fre]=0;
		r[fre]=0;
		return 0;
	}
	if (a>=d[pp]) inst(a,r[pp],pp,1);
	else
	{
		m[pp]++;
		inst(a,l[pp],pp,0);
	}
}

int main()
{
	long i,n,mm,tag;
	char c;
	scanf("%d%d",&n,&mm);
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(d,0,sizeof(d));
	memset(m,0,sizeof(m));
	scanf("%c",&c);
	for (i=1;i<=mm;i++)
	{
		scanf("%c%d",&c,&tag);
		if (c==68) inst(tag+fd(tag,l[0]),l[0],0,0);
		else printf("%d\n",tag+fd(tag,l[0]));
		scanf("%c",&c);
	}
	return 0;
}
