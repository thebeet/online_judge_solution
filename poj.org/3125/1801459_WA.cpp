#include <stdio.h>
#include <memory.h>

long q[120];
long n;

long ismax(long p)
{
	long i;
	for (i=p+1;i<p+n;i++)
		if (q[i%n]>q[p])
		{
			p=i%n;
		}
	return p;
}

int main()
{
	long ti,tn,i,m,p,ret,s;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		s=0;
		scanf("%d%d",&n,&m);
		memset(q,0,sizeof(q));
		for (i=0;i<n;i++)
			scanf("%d",&q[i]);
		p=0;
		while (q[m]>0)
		{
			ret=ismax(p);
			if (ret!=p)
			{
				p=ret;
			}
			q[p]=0;
			s++;
			p=(p+1)%n;
		}
		printf("%d\n",s);
	}
	return 0;
}


