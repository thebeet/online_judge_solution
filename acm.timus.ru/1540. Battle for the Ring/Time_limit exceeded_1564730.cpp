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
/*
#define MAXN 110

long nim;
long m[MAXN];
long ring[MAXN];
long ringnim[55][MAXN][MAXN];
long ringnims[55][MAXN];

long n;

long dp(long id,long f,long t)
{
	long i,j;
	bool nimbool[MAXN];
	if (ringnim[id][f][t]>0) return ringnim[id][f][t];
	memset(nimbool,false,sizeof(nimbool));
	for (l=k;l<=k+h;l++)
	{
		ringnims[id][l]=0;
		p=k;
		for (j=k;j<=k+h;j++)
		{
			if (ring[j]<=ring[l])
			{
				ringnims[i][l]^=ringnim[i][p][j-1];
				p=j+1;
			}
		}
		ringnims[i][l]^=ringnim[i][p][k+h];
		nimbool[ringnims[i][l]]=true;
	}
	for (l=1;;l++)
	{
		if (nimbool[l]==false)
		{
			ringnim[i][k][k+h]=l;
			break;
		}
	}



int main()
{
	long i,j,h,k,l,p;
	scanf("%ld",&n);

	for (i=1;i<=n;i++)
	{
		scanf("%ld",&m[i]);
		for (j=1;j<=m[i];j++)
		{
			scanf("%ld",&ring[j]);
			ringnim[i][j][j]=1;
		}
		for (h=1;h<m[i];h++)
		{
			for (k=1;k<=m[i]-h;k++)
			{
			}
		}
		nim^=ringnim[i][1][m[i]];
	}
	if (nim>0)
	{
		printf("G\n");
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m[i];j++)
			{
				if ((ringnims[i][j]^nim^ringnim[i][1][m[i]])==0)
				{
					printf("%ld %ld\n",i,j);
					return 0;
				}
			}
		}
	}
	else
	{
		printf("S\n");
	}
	return 0;
}
*/