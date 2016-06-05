#include <stdio.h>
#include <memory.h>

#define MAXN 110

long m,n,s;
long map[MAXN][MAXN];
bool gone[MAXN];
bool goned[MAXN];
long dl[MAXN];
long pr[MAXN];
long ss[MAXN];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long bfs(long p,bool flag)
{
	long i,j,ans,f,ansp;
	memset(dl,0,sizeof(dl));
	memset(pr,0,sizeof(pr));
	memset(ss,0,sizeof(ss));
	memset(gone,false,sizeof(gone));
	dl[0]=1;
	dl[1]=p;
	i=0;
	gone[p]=true;
	goned[p]=true;
	ans=0;
	ansp=p;
	while (i<dl[0])
	{
		i++;
		f=dl[i];
		for (j=1;j<=m;j++)
		{
			if ((map[f][j]>0) && (j!=pr[i]))
			{
				if (gone[j]) 
				{
					return 100000000;
				}
				else
				{
					gone[j]=true;
					goned[j]=true;
					dl[0]++;
					dl[dl[0]]=j;
					pr[dl[0]]=f;
					ss[j]=ss[f]+map[f][j];
					if (ss[j]>ans)
					{
						ans=ss[j];
						ansp=j;
					}
				}
			}
		}
	}
	if (flag) 
	{
		return bfs(ansp,false);
	}
	else
	{
		return ans;
	}
}

int main()
{
	long i,ret,p,q,l;
	scanf("%ld%ld%ld",&m,&n,&s);
	if (m<=n)
	{
		printf("YES\n");
		return 0;
	}
	memset(map,0,sizeof(map));
	memset(goned,false,sizeof(goned));
	for (i=1;i<=n;i++)
	{
		scanf("%ld%ld%ld",&p,&q,&l);
		if (map[p][q]!=0)
		{
			printf("YES\n");
			return 0;
		}
		map[p][q]=l;
		map[q][p]=l;
	}
	for (i=1;i<=m;i++)
	{
		if (goned[i]==false)
		{
			ret=bfs(i,true);
			if (ret>=s)
			{
				printf("YES\n");
				return 0;
			}
		
		}
	}
	printf("NO\n");
	return 0;
}

