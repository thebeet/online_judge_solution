#include <stdio.h>
#include <memory.h>

long map[510][510];
long wei[510][510];
long gotime[510];
long n;

long td[510];
long tt[510];

void swap(long &a,long &b)
{
	long tmp;
	tmp=a;
	a=b;
	b=tmp;
}

void turnup(long p)
{
	long pt;
	if (p==1) return;
	pt=p>>1;
	if (td[p]<td[pt])
	{
		swap(td[p],td[pt]);
		swap(tt[p],tt[pt]);
		turnup(pt);
	}
	return;
}
		
void turndown(long p)
{
	long pt;
	pt=p<<1;
	if (pt>td[0]) return;
	if ((pt<td[0]) && (td[pt]>td[pt+1]))
	{
		pt++;
	}
	if (td[p]>td[pt])
	{
		swap(td[p],td[pt]);
		swap(tt[p],tt[pt]);
		turndown(pt);
	}
	return;
}

void del(/*long p*/)  //p=1;
{
	swap(td[1],td[td[0]]);
	swap(tt[1],tt[td[0]]);
	td[0]--;
	turndown(1);
}

void insert(long d,long t)
{
	td[0]++;
	td[td[0]]=d;
	tt[td[0]]=t;
	turnup(td[0]);
	return;
}

int main()
{
	long i,m,a,b,t,w;
	scanf("%ld%ld",&n,&m);
	memset(map,0,sizeof(map));
	memset(wei,0,sizeof(wei));
	for (i=1;i<=m;i++)
	{
		scanf("%ld%ld%ld%ld",&a,&b,&t,&w);
		w=(w-3000000)/100;
		if (w<0) w=0;
		map[a][b]=t;
		wei[a][b]=w;
		map[b][a]=t;
		wei[b][a]=w;
	}
	a=0;
	b=10000010;
	while (a+1!=b)
	{
		m=(a+b)>>1;
		memset(gotime,1,sizeof(gotime));
		memset(td,0,sizeof(td));
		memset(tt,0,sizeof(tt));
		insert(0,1);
		insert(10000000,1);
		while ((gotime[n]>1440) && (td[1]<=1440))
		{
			t=tt[1];
			gotime[t]=td[1];
			del();
			for (i=1;i<=n;i++)
			{
				if (wei[t][i]>=m)
				{
					insert(gotime[t]+map[t][i],i);
				}
			}
		}
		if (gotime[n]>1440) 
		{
			b=m;
		}
		else
		{
			a=m;
		}
	}
	printf("%ld\n",a);
	return 0;
}
