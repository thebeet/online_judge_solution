#include <stdio.h>
#include <math.h>
#include <memory.h>
#define mx 210
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
	mem