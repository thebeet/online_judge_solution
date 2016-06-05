#include <stdio.h>
#include <memory.h>

long k[110];
long st[110][60];
long cc[20];
long bt[110];
long bk[110];
long dl[10000];
long c,m;

long findempty()
{
	long i;
	for (i=1;i<=m;i++)
		if (cc[i]<c) break;
	return i;
}

int main()
{
	long i,j,h,mt,mp,n,p,ans,tb,ep,ep2;
	scanf("%d%d%d",&m,&c,&n);
	while (m)
	{
		memset(st,0,sizeof(st));
		memset(k,0,sizeof(k));
		memset(dl,0,sizeof(dl));
		memset(cc,0,sizeof(cc));
		memset(bt,0,sizeof(bt));
		for (i=1;i<=100;i++)
			bk[i]=m+1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
			for (j=1;j<=k[i];j++)
				scanf("%d",&st[i][j]);
		}
		for (p=1;p<=50;p++)
			for (i=1;i<=n;i++)
			{
				if (st[i][p])
				{
					dl[0]++;
					dl[dl[0]]=st[i][p];
				}
			}
		ans=0;
		for (i=1;i<=dl[0];i++)
		{
			tb=dl[i];
			ans+=bk[tb];
			cc[bk[tb]]--;
			bk[tb]=1;
			bt[tb]=0;
			ep=findempty();
			cc[ep]++;
			ans+=ep;
			if (ep!=1)
			{
				mt=0;
				for (h=1;h<=100;h++)
					if (bt[h]>mt)
					{
						mt=bt[h];
						mp=h;
					}
				bt[mp]=0;
				ep2=findempty();
				bk[mp]=ep2;
				cc[ep2]++;
				ans+=(1+ep2);
				cc[ep]--;
				ans+=(ep+1);
			}
			for (j=1;j<=100;j++)
				if (bk[j]==1) bt[j]++;
		}
		printf("%d\n",ans);
		scanf("%d%d%d",&m,&c,&n);
	}
	return 0;
}












