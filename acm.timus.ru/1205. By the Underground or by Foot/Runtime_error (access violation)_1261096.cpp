#include <stdio.h>
#include <math.h>
#include <memory.h>
#define mx 12
double x[mx];
double y[mx];
double tm[mx][mx];
long map[mx];
long dl[mx];
long ans[mx];
double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	long i,j,n,f,t,mp,mf;
	double sf,su,minl;
	scanf("%lf%lf",&sf,&su);
	su=sf/su;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		for (j=1;j<i;j++)
		{
			tm[i][j]=dist(x[i],y[i],x[j],y[j])/sf;
			tm[j][i]=tm[i][j];
		}
	}
	scanf("%d%d",&f,&t);
	while ((f>0) && (t>0))
	{
		tm[f][t]=tm[f][t]*su;
		tm[t][f]=tm[f][t];
		scanf("%d%d",&f,&t);
	}
	n++;
	scanf("%lf%lf",&x[n],&y[n]);
	for (j=1;j<n;j++)
	{
		tm[n][j]=dist(x[n],y[n],x[j],y[j])/sf;
		tm[j][n]=tm[n][j];
	}
	n++;
	scanf("%lf%lf",&x[n],&y[n]);
	for (j=1;j<n;j++)
	{
		tm[n][j]=dist(x[n],y[n],x[j],y[j])/sf;
		tm[j][n]=tm[n][j];
	}
	memset(map,0,sizeof(map));
	dl[0]=1;
	dl[1]=n-1;
	map[n-1]=10000;
	while (map[n]==0)
	{
		minl=tm[n-1][n];
		mp=0;
		for (i=1;i<=dl[0];i++)
		{
			for (j=1;j<=n;j++) 
				if ((tm[j][dl[i]]<=minl) && (map[j]==0))
				{
					minl=tm[j][dl[i]];
					mp=j;
					mf=dl[i];
				}
		}
		dl[0]++;
		dl[dl[0]]=mp;
		map[mp]=mf;
	}
	ans[0]=0;
	minl=0;
	mp=n;
	while (mp!=n-1)
	{
		minl=minl+tm[mp][map[mp]];
		if (tm[mp][map[mp]]<dist(x[mp],y[mp],x[map[mp]],y[map[mp]]))
		{
			if (ans[ans[0]]!=mp)
			{
				ans[0]++;
				ans[ans[0]]=mp;
			}
			ans[0]++;
			ans[ans[0]]=map[mp];
		}
		mp=map[mp];
	};
	printf("%.7f\n",minl);
	printf("%d",ans[0]);
	for (i=ans[0];i>0;i--)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
		