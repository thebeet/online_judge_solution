#include <stdio.h>
#include <memory.h>

#define MAXN 110

long m[MAXN];
long ring[MAXN];
long ringnim[55][MAXN][MAXN];
bool nimuse[MAXN];

long findnims(bool nimuse[MAXN])
{
	long i;
	for (i=1;;i++)
	{
		if (!nimuse[i]) return i;
	}
}

long calcnims(long i,long f,long t)
{
	long j,h,p,thenims;
	bool nimuse[MAXN];
	if (f>t) return 0;
	if (f==t) return 1;
	if (f+1==t)
	{
		if (nimuse[f]==nimuse[t])
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (ringnim[i][f][t]>0) return ringnim[i][f][t];
	memset(nimuse,false,sizeof(nimuse));
	for (j=f;j<=t;j++)
	{
		p=f;
		thenims=0;
		for (h=f;h<=t;h++)
		{
			if (ring[j]>=ring[h])
			{
				thenims^=calcnims(i,p,h-1);
				p=h+1;
			}
		}
		thenims^=calcnims(i,p,t);
		nimuse[thenims]=true;
	}
	return findnims(nimuse);
}


int main()
{
	long i,j,h,n,p;
	//init
	memset(m,0,sizeof(m));
	memset(ring,0,sizeof(ring));
	memset(ringnim,0,sizeof(ringnim));
	scanf("%ld",&n);
	for (i=1;i<=n;i++)
	{
		memset(nimuse,false,sizeof(nimuse));
		scanf("%ld",&m[i]);
		for (j=1;j<=m[i];j++)
		{
			scanf("%ld",&ring[j]);
		}
		for (j=1;j<=m[i];j++)
		{
			p=1;
			for (h=1;h<=m[i];h++)
			{
				if (ring[j]>=ring[h])
				{
					ringnim[i][j][0]^=calcnims(i,p,h-1);
					p=h+1;
				}
			}
			ringnim[i][j][0]^=calcnims(i,p,m[i]);
			nimuse[ringnim[i][j][0]]=true;
		}
		ringnim[i][0][0]=findnims(nimuse);
		ringnim[0][0][0]^=ringnim[i][0][0];
	}
	if (ringnim[0][0][0]==0)
	{
		printf("S\n");
		return 0;
	}
	else
	{
		printf("G\n");
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m[i];j++)
			{
				if ((ringnim[0][0][0]^ringnim[i][0][0]^ringnim[i][j][0])==0)
				{
					printf("%ld %ld\n",i,j);
					return 0;
				}
			}
		}
	}
}
