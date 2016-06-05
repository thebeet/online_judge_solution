#include <stdio.h>
#include <memory.h>

#define MAXN 200010

long js[MAXN];
long f[MAXN];
long s[MAXN];

long find(long p)
{
	if (f[p]==p) return p;
	f[p]=find(f[p]);
	return f[p];
}

int main()
{
	long i,j,n,m,op,a,b,ra,rb,d;
	scanf("%d%d",&n,&m);
	memset(js,0,sizeof(js));
	for (i=1;i<=n;i++)
	{
		f[i]=i;
		s[i]=1;
	}
	js[1]=n;
	d=n;
	for (i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d",&a);
			j=0;
			a=d-a+1;
			while (a>0)
			{
				j++;
				a-=js[j];
			}
			printf("%d\n",j);
		}
		else
		{
			scanf("%d%d",&a,&b);
			ra=find(a);
			rb=find(b);
			if (ra==rb)
				continue;
			d--;
			js[s[ra]]--;
			js[s[rb]]--;
			s[ra]+=s[rb];
			js[s[ra]]++;
			f[rb]=ra;
		}
	}
	return 0;
}
