#include <stdio.h>
#include <memory.h>

long lj[1001][1001];
long x[1001];
long y[1001];
long s[1001];

void d(long a,long p)
{
	s[a]=1;
	long i,t;
	for (i=1;i<=lj[a][0];i++)
	{
		t=lj[a][i];
		if (t==p) continue;
		d(t,a);
	}
	s[p]=s[p]+s[a];
}

void dfs(long a,long xx,long yy,long p)
{
	long i,t;
	x[a]=xx;
	y[a]=yy;
	for (i=1;i<=lj[a][0];i++)
	{
		t=lj[a][i];
		if (t==p) continue;
		dfs(t,xx+1,yy,a);
		yy=yy+s[t];
	}
}

int main()
{
	long i,f,t,n;
	scanf("%d",&n);
	memset(lj,false,sizeof(lj));
	memset(s,0,sizeof(s));
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&f,&t);
		lj[f][0]++;
		lj[f][lj[f][0]]=t;
		lj[t][0]++;
		lj[t][lj[t][0]]=f;
	}
	d(1,0);
	dfs(1,0,0,0);
	for (i=1;i<=n;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}
	