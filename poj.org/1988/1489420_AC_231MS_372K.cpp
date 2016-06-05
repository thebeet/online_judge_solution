#include <stdio.h>
#include <memory.h>

#define MAXN 30010

long f[MAXN];
long h[MAXN];
long s[MAXN];

long find(long p)
{
	long hs,rt,rrt,t,pr;
	hs=0;
	rt=p;
	while (f[rt]>0)
	{
		hs+=h[rt];
		rt=f[rt];
	}
	pr=h[p];
	h[p]=hs;
	rrt=rt;
	rt=p;
	while (f[rt]>0)
	{
		hs-=pr;	
		pr=h[f[rt]];
		h[f[rt]]=hs;
		t=rt;
		rt=f[rt];
		f[t]=rrt;
	}
	return rrt;
}

void mov(long p1,long p2)
{
	long r1,r2;
	r1=find(p1);
	r2=find(p2);
	f[r1]=r2;
	h[r1]=s[r2];
	s[r2]+=s[r1];
}

int main()
{
	long i,n,a,b;
	char b1,op; 
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	memset(h,0,sizeof(h));
	for (i=0;i<MAXN;i++)
		s[i]=1;
	for (i=1;i<=n;i++)
	{
		scanf("%c%c",&b1,&op);
		if (op=='M')
		{
			scanf("%d%d",&a,&b);
			mov(a,b);
		}
		else
		{
			scanf("%d",&a);
			find(a);
			printf("%d\n",h[a]);
		}
	}
	return 0;
}



