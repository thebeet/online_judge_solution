#include <stdio.h>
#include <memory.h>

#define MAXN 1010

long r[MAXN];
long d[MAXN];
long m[MAXN];
bool map[MAXN][MAXN];
long l[MAXN];

long gcd(long a,long b)
{
	long r;
	if (a<0) a=-a;
	if (b<0) b=-b;
	if (b>a) 
	{
		r=b;
		b=a;
		a=r;
	}
	while (b>0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	long i,n,t,v,gc,pe;
	scanf("%d",&n);
	memset(d,0,sizeof(d));
	memset(map,false,sizeof(map));
	for (i=1;i<=n;i++)
		m[i]=1;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
		scanf("%d",&t);
		while (t>0)
		{
			map[i][t]=true;
			scanf("%d",&t);
		}
	}
	scanf("%d%d",&t,&v);
	l[0]=1;
	l[1]=t;
	d[t]=v;
	m[t]=1;
	pe=1;
	while (l[0]<=pe)
	{
		t=l[l[0]];
		for (i=1;i<=n;i++)
			if (map[t][i])
			{
				map[i][t]=false;
				pe++;
				l[pe]=i;
				d[i]=-d[t]*r[t];
				m[i]=m[t]*r[i];
				gc=gcd(m[i],d[i]);
				m[i]/=gc;
				d[i]/=gc;
			}
		l[0]++;
	}
	for (i=1;i<=n;i++)
		printf("%d/%d\n",d[i],m[i]);
	return 0;
}





