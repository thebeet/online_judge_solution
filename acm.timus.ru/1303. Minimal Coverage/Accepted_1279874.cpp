#include <stdio.h>

#define MAXN 100004

long f[MAXN];
long e[MAXN];
long ans[MAXN];

void sort(long l,long r)
{
	long i,j,xf,xe,y;
	i=l;
	j=r;
	xf=f[(l+r)/2];
	xe=e[(l+r)/2];
	for (;;)
	{
		while ((f[i]<xf) || ((f[i]==xf) && (e[i]>xe)))
			i++;
		while ((f[j]>xf) || ((f[j]==xf) && (e[j]<xe)))
			j--;
		if (i<=j)
		{
			y=f[i];
			f[i]=f[j];
			f[j]=y;
			y=e[i];
			e[i]=e[j];
			e[j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

int main()
{
	long i,j,n,m,ff,mm,p,pp;
	bool flag;
	scanf("%d",&m);
	n=1;
	scanf("%d%d",&f[n],&e[n]);
	while ((f[n]!=0) || (e[n]!=0))
	{
		if (f[n]==e[n]) n--;
		n++;
		scanf("%d%d",&f[n],&e[n]);
	}
	n--;
	sort(1,n);
	ans[0]=0;
	p=1;

	for (i=0;i<m;i++)
	{
		flag=false;
		mm=-1000000000;
		for (j=p;j<=n;j++)
		{
			if (f[j]>i) 
				break;
			else
			{
				if (mm<e[j])
				{
					flag=true;
					pp=j;
					mm=e[j];
				}
			}
		}
		p=j;
		if ((flag) && (mm>i))
		{
			ans[0]++;
			ans[ans[0]]=pp;
			i=mm-1;
		}
		else
		{
			printf("No solution\n");
			return 0;
		}
	}
	printf("%d\n",ans[0]);
	for (i=1;i<=ans[0];i++)
		printf("%d %d\n",f[ans[i]],e[ans[i]]);
	return 0;
}
