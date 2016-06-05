#include <stdio.h>

long ans[1000010];

long crt(long a[10],long n)
{
	long i,j,s,nn;
	bool flag;
	if (a[0]==n)
	{
		s=0;
		for (i=1;i<=n;i++)
			s=s*10+a[i];
		ans[0]++;
		ans[ans[0]]=s;
		if (ans[0]<1000001) return 0;
		else return 1;
	}
	a[0]++;
	nn=a[0];
	for (i=0;i<=9;i++)
	{
		flag=true;
		if ((a[0]==1) && (i==0)) continue;
		for (j=1;j<a[0];j++)
			if (a[j]==i) 
			{
				flag=false;
				break;
			}
		if (flag)
		{
			a[a[0]]=i;
			if (crt(a,n)==1) return 1;
			a[0]=nn;
		}
	}
	return 0;
}

void make()
{
	long i;
	long a[10];
	a[0]=0;
	for (i=1;i<=10;i++)
	{
		if (crt(a,i)>0) break;
		a[0]=0;
	}
}
		

int main()
{
	long n;
	ans[0]=0;
	make();
	scanf("%d",&n);
	while (n>0)
	{
		printf("%d\n",ans[n]);
		scanf("%d",&n);
	}
	return 0;
}

