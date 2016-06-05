#include <stdio.h>

long a[2001];
long id[2001];
long dp[2001][2001];

void ss(long l,long r)
{
	long i,j,x,y;
	i=l;j=r;x=a[(i+j)/2];
	for (;;)
	{
		while (x>a[i])
			i++;
		while (x<a[j])
			j--;
		if (i<=j)
		{
			y=a[i];
			a[i]=a[j];
			a[j]=y;
			y=id[i];
			id[i]=id[j];
			id[j]=y;
			i++;
			j--;
		}
		if (i>j) break;
	}
	if (l<j) ss(l,j);
	if (i<r) ss(i,r);
}

int main()
{
	long i,j,n,p1,p2,nn,m,pm1,pm2;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		id[i]=i;
	}
	ss(1,n);

	nn=n;
	n=1;
	for (i=2;i<=nn;i++)
		if (a[i]==a[i-n])
			n++;
		else
		{
			a[i-n+1]=a[i];
			id[i-n+1]=id[i];
		}
	n=nn-n+1;
	if (n==1)
	{
		printf("%d\n",n);
		printf("%d\n",id[1]);
		return 0;
	}
	m=1;
	pm1=2;
	pm2=1;
	for (i=2;i<=n;i++)
	{
		p1=1;
		for (j=1;j<i;j++)
		{
			dp[i][j]=1;
			while (a[p1]+a[i]<a[j]+a[j])
				p1++;
			if ((a[p1]+a[i]>a[j]+a[j]) || (p1==j)) continue;
			dp[i][j]=dp[j][p1]+1;
			if (dp[i][j]>m) 
			{
				m=dp[i][j];
				pm1=i;
				pm2=j;
			}
		}
	}
	printf("%d\n",m+1);
	printf("%d %d",id[pm1],id[pm2]);
	for (i=pm2-1;i>=1;i--)
		if (a[i]+a[pm1]==a[pm2]+a[pm2])
		{
			printf(" %d",id[i]);
			pm1=pm2;
			pm2=i;
		}
	printf("\n");
	return 0;
}




