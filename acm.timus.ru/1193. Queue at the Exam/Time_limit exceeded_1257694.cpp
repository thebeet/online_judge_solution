#include <stdio.h>
struct student
{
	int t1,t2,t3;
};
student ss[102];
student swaptmp;
int n;

bool check()
{
	int i,t;
	t=-1000;
	for (i=1;i<=n;i++)
	{
		if (t<ss[i].t1) t=ss[i].t1;
		t=t+ss[i].t2;
		if (t>ss[i].t3) return false;
	}
	return true;
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d%d",&ss[i].t1,&ss[i].t2,&ss[i].t3);
	for (i=1;i<=n;i++)
		for (j=i+1;j<=n;j++)
			if (ss[i].t1>ss[j].t1)
			{
				swaptmp=ss[i];
				ss[i]=ss[j];
				ss[j]=swaptmp;
			}
	for (i=0;;i++)
	{
		if (check())
		{
			printf("%d\n",i);
			break;
		}
		for (j=1;j<=n;j++)
			ss[j].t1--;
	}
	return 0;
}

