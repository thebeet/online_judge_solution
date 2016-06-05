#include <stdio.h>
#include <memory.h>

#define MAXN 150

long nim;
bool nimbool[MAXN];
long m[MAXN];
long ring[MAXN];
long ringnim[55][MAXN][MAXN];
long ringnims[55][MAXN];

long n;

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
				memset(nimbool,false,sizeof(nimbool));
				for (l=k;l<=k+h;l++)
				{
					ringnims[i][l]=0;
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
