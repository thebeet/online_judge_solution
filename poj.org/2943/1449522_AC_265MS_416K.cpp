#include <stdio.h>
#include <memory.h>

bool ma[205][305];
bool el[205][305];
long mt[205][305];
long p[205];

int main()
{
	long i,j,k,n,m,t,s;
	bool flag;
	scanf("%d%d",&n,&m);
	while (m>0)
	{
		memset(ma,false,sizeof(ma));
		memset(el,false,sizeof(el));
		memset(mt,0,sizeof(mt));
		for (i=1;i<=m;i++)
		{
			scanf("%d",&mt[i][0]);
			for (j=1;j<=mt[i][0];j++)
			{
				scanf("%d",&mt[i][j]);
				ma[i][mt[i][j]]=true;
			}
		}
		for (i=1;i<=m;i++)
			p[i]=i;
		for (i=1;i<=m;i++)
			for (j=1;j<i;j++)
				if (mt[p[j]][0]>mt[p[i]][0])
				{
					t=p[j];
					p[j]=p[i];
					p[i]=t;
				}
		for (i=1;i<m;i++)
		{
			for (j=i+1;j<=m;j++)
			{
				flag=true;
				for (k=1;k<=mt[p[i]][0];k++)
					if (ma[p[j]][mt[p[i]][k]]==false)
					{
						flag=false;
						break;
					}
				if (flag)
					for (k=1;k<=mt[p[i]][0];k++)
						el[p[j]][mt[p[i]][k]]=true;
			}
		}
		s=0;
		for (i=1;i<=m;i++)
		{
			flag=true;
			for (j=1;j<=mt[i][0];j++)
				if (el[i][mt[i][j]]==false)
				{
					flag=false;
					break;
				}
			if (flag) s++;
		}
		printf("%d\n",s);
		scanf("%d%d",&n,&m);
	}
	return 0;
}




