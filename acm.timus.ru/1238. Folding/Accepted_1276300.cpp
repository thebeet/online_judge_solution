#include <stdio.h>
#include <memory.h>

#define MAXN 110

long dp[MAXN][MAXN];
long s[MAXN][MAXN];
bool fd[MAXN][MAXN];
char c[MAXN];

void out(long f,long l)
{
	long i;
	if (s[f][l]==l)
	{
		for (i=f;i<f+l;i++)
			printf("%c",c[i]);
		return;
	}
	if (fd[f][l])
	{
		printf("%d(",l/dp[f][l]);
		out(f,dp[f][l]);
		printf(")");
	}
	else
	{
		out(f,dp[f][l]);
		out(f+dp[f][l],l-dp[f][l]);
	}
}


int main()
{
	long i,j,k,h,g,n,dm,t;
	bool flag;
	memset(fd,false,sizeof(fd));
	scanf("%c",&c[1]);
	n=1;
	while (c[n]>20)
	{
		n++;
		scanf("%c",&c[n]);
	}
	n--;

	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			dp[i][j]=1;
			s[i][j]=j;
		}
	for (g=2;g<=n;g++)
		for (i=1;i<=(n-g+1);i++)
		{
			for (j=1;j<g;j++)
			{
				dm=s[i][j]+s[i+j][g-j];
				if (dm<s[i][g])
				{
					s[i][g]=dm;
					dp[i][g]=j;
				}
			}
			for (j=2;j<=g;j++)
				if ((g%j)==0)
				{
					t=g/j;
					flag=true;
					for (k=i+t;k<i+g;k=k+t)
					{
						for (h=k;h<k+t;h++)
							if (c[h]!=c[i+h-k])
							{
								flag=false;
								break;
							}
					}
					if (flag)
					{
						t=g/j;
						dm=3;
						if (j>9) dm++;
						if (j>99) dm++;
						dm+=s[i][t];
						if (dm<s[i][g])
						{
							s[i][g]=dm;
							dp[i][g]=t;
							fd[i][g]=true;
						}
					}
				}
		}
	out(1,n);
	printf("\n");
	return 0;
}



	