#include <stdio.h>
#include <memory.h>

long map[101][101];
long sh[101];
long sw[101];

int main()
{
	long tn,ti,i,j,ki,kj,n,m,ans,t,ta;
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		memset(sh,0,sizeof(sh));
		memset(sw,0,sizeof(sw));
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;i++)
			for (j=1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
				sh[i]+=map[i][j];
				sw[j]+=map[i][j];
			}
		ans=0;
		for (i=2;i<=m;i++)
			ans+=sh[i]*(i-1);
		for (j=2;j<=n;j++)
			ans+=sw[j]*(j-1);
		t=ans;
		for (i=1;i<=m;i++)
		{
			if (i!=1)
			{
				for (ki=1;ki<i;ki++)
					t=t+sh[ki];
				for (ki=i;ki<=n;ki++)
					t=t-sh[ki];
			}
			ta=t;
			for (j=2;j<=n;j++)
			{
				for (kj=1;kj<j;kj++)
					ta=ta+sw[kj];
				for (kj=j;kj<=n;kj++)
					ta=ta-sw[kj];
				if (ta<ans) ans=ta;
			}
		}
		printf("%d blocks\n",ans);
	}
	return 0;
}




