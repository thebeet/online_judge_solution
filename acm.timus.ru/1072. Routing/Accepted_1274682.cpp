#include <stdio.h>
#include <memory.h>

unsigned long ip[100][6][3];
long k[100];
long map[100][100];
long pr[100];
long dl[100];
long ans[100];

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

int main()
{
	long i,j,h,l,n,f,t,pt;
	long p1,p2,p3,p4;
	bool flag;
	scanf("%d",&n);
	memset(map,1,sizeof(map));
	for (i=1;i<=n;i++)
	{
		map[i][i]=0;
		scanf("%d",&k[i]);
		for (j=1;j<=k[i];j++)
		{
			scanf("%d.%d.%d.%d",&p1,&p2,&p3,&p4);
			ip[i][j][1]=(p1<<24)+(p2<<16)+(p3<<8)+p4;
			scanf("%d.%d.%d.%d",&p1,&p2,&p3,&p4);
			ip[i][j][2]=(p1<<24)+(p2<<16)+(p3<<8)+p4;
			ip[i][j][0]=ip[i][j][1]&ip[i][j][2];
		}

	}

	for (i=2;i<=n;i++)
		for (j=1;j<i;j++)
		{
			flag=false;
			for (h=1;h<=k[i];h++)
			{
				for (l=1;l<=k[j];l++)
					if (ip[i][h][0]==ip[j][l][0])
					{
						flag=true;
						break;
					}
				if (flag) break;
			}
			if (flag) 
			{
				map[i][j]=1;
				map[j][i]=1;
			}
		}
	memset(pr,0,sizeof(pr));
	scanf("%d%d",&f,&t);
	dl[0]=1;
	dl[100]=1;
	dl[1]=f;
	while ((dl[0]<=dl[100]) && (pr[t]==0))
	{
		pt=dl[dl[0]];
		dl[0]++;
		for (i=1;i<=n;i++)
			if ((pr[i]==0) && (map[pt][i]==1))
			{
				dl[100]++;
				dl[dl[100]]=i;
				pr[i]=pt;
			}
	}
	if (pr[t]==0)
		printf("No\n");
	else
	{
		ans[0]=1;
		pt=t;
		ans[1]=t;
		while (pt!=f)
		{
			pt=pr[pt];
			ans[0]++;
			ans[ans[0]]=pt;
		}
		printf("Yes\n");
		for (i=ans[0];i>1;i--)
			printf("%d ",ans[i]);
		printf("%d\n",ans[1]);
	}
	return 0;
}



