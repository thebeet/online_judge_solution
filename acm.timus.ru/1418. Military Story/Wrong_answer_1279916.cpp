#include <stdio.h>
#include <memory.h>

#define MAXN 5000

long x[MAXN];
long y[MAXN];
long st[MAXN];
bool us[MAXN];

void sort(long l,long r)
{
	long i,j,xx,xy,yy;
	i=l;
	j=r;
	xx=x[(l+r)/2];
	xy=y[(l+r)/2];
	for (;;)
	{
		while ((x[i]<xx) || ((x[i]==xx) && (y[i]<xy)))
			i++;
		while ((x[j]>xx) || ((x[j]==xx) && (y[j]>xy)))
			j--;
		if (i<=j)
		{
			yy=x[i];
			x[i]=x[j];
			x[j]=yy;
			yy=y[i];
			y[i]=y[j];
			y[j]=yy;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}

long xj(long x0,long y0,long x1,long y1,long x2,long y2)
{
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}


int main()
{
	long i,n,ans,di,p,ret;
	bool flag;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	ans=0;
	sort(1,n);
	while (n>=3)
	{
		memset(us,true,sizeof(us));
		i=3;
		st[0]=2;
		st[1]=1;
		st[2]=2;
		flag=false;
		while (i<=n)
		{
			ret=xj(x[st[st[0]-1]],y[st[st[0]-1]],x[st[st[0]]],y[st[st[0]]],x[i],y[i]);
			if (ret<0)
			{
				st[0]++;
				st[st[0]]=i;
				i++;
				flag=true;
			}
			else
			{
				if (ret==0)
				{
					st[0]++;
					st[st[0]]=i;
					i++;
				}
				else
					st[0]--;
			}
		}
		for (i=1;i<=st[0];i++)
			us[st[i]]=false;
		us[1]=true;
		i=n-1;
		while (i>=1)
		{
			if (!us[i]) 
			{
				i--;
				continue;
			}
			ret=xj(x[st[st[0]-1]],y[st[st[0]-1]],x[st[st[0]]],y[st[st[0]]],x[i],y[i]);
			if (ret<0)
			{
				st[0]++;
				st[st[0]]=i;
				i--;
				flag=true;
			}
			else
			{
				if (ret==0)
				{
					st[0]++;
					st[st[0]]=i;
					i--;
				}
				else
					st[0]--;
			}
		}
		for (i=1;i<=st[0];i++)
			us[st[i]]=false;
		if (flag) 
			ans++;
		di=0;
		for (i=1;i<=n;i++)
			if (!us[i])
			{
				di++;
			}
			else
			{
				x[i-di]=x[i];
				y[i-di]=y[i];
			}
		n-=st[0];
	}
	printf("%d\n",ans);
	return 0;
}

