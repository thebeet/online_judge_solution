#include <stdio.h>
#include <memory.h>

#define MAXN 5001

long lh[MAXN];
long we[MAXN];
bool d[MAXN];

void sort(long l,long r)
{
	long i,j,xl,xw,y;
	i=l;j=r;
	xl=lh[(i+j)/2];
	xw=we[(i+j)/2];
	for (;;)
	{
		while ((lh[i]>xl) || ((lh[i]==xl) && (we[i]>xw)))
			i++;
		while ((lh[j]<xl) || ((lh[j]==xl) && (we[j]<xw)))
			j--;
		if (i<=j)
		{
			y=lh[i];
			lh[i]=lh[j];
			lh[j]=y;
			y=we[i];
			we[i]=we[j];
			we[j]=y;
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
	long ti,tn,i,n,j,s,pl,pw;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(d,true,sizeof(d));
		s=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d",&lh[i],&we[i]);
		sort(1,n);
		for (i=1;i<=n;i++)
			if (d[i])
			{
				s++;
				pw=we[i];
				for (j=i+1;j<=n;j++)
					if ((d[j]) && (pw>=we[j]))
					{
						pw=we[j];
						d[j]=false;
					}
			}
		printf("%d\n",s);
	}
	return 0;
}




