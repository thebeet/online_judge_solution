#include <stdio.h>
#include <memory.h>

#define MAXN 1010

long d[MAXN][MAXN];
long id[MAXN][MAXN];
long ans[MAXN];
long heap[MAXN];
long heapid[MAXN];

void turnup(long p)
{
	long pt,t;
	if (p<=1) return;
	pt=p>>1;
	if (heap[p]>heap[pt])
	{
		t=heap[p];
		heap[p]=heap[pt];
		heap[pt]=t;
		t=heapid[p];
		heapid[p]=heapid[pt];
		heapid[pt]=t;
		turnup(t);
	}
}

void turndown(long p)
{
	long pt,t;;
	pt=p<<1;
	if (pt>heap[0]) return;
	if (((pt+1)<=heap[0]) && (heap[pt]<heap[pt+1])) pt++;
	if (heap[p]<heap[pt])
	{
		t=heap[p];
		heap[p]=heap[pt];
		heap[pt]=t;
		t=heapid[p];
		heapid[p]=heapid[pt];
		heapid[pt]=t;
		turndown(t);
	}
}

void inst(long rew,long index)
{
	heap[0]++;
	heap[heap[0]]=rew;
	heapid[heap[0]]=index;
	turnup(heap[0]);
}

void out()
{
	if (heap[0]>0)
	{
		ans[0]++;
		ans[ans[0]]=heapid[1];
		heap[1]=heap[heap[0]];
		heapid[1]=heapid[heap[0]];
		heap[0]--;
		turndown(1);
	}
}

int main()
{
	long i,j,n,day,reward;
	scanf("%d",&n);
	memset(ans,0,sizeof(ans));
	memset(d,0,sizeof(d));
	memset(id,0,sizeof(id));
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&day,&reward);
		if (day>=n)
		{
			ans[0]++;
			ans[ans[0]]=i;
		}
		else
		{
			d[day][0]++;
			d[day][d[day][0]]=reward;
			id[day][d[day][0]]=i;
		}
	}
	for (i=n-1;i>0;i--)
	{
		if (d[i][0]>0)
			for (j=1;j<=d[i][0];j++)
				inst(d[i][j],id[i][j]);
		out();
	}
	printf("%d\n",ans[0]);
	for (i=ans[0];i>1;i--)
		printf("%d ",ans[i]);
	printf("%d\n",ans[1]);
	return 0;
}





	
