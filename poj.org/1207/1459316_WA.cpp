#include <stdio.h>
#include <memory.h>

long ans[2200001];

long calc(long n)
{
	if (ans[n]>0) return ans[n];
	if ((n%2)==0) 
	{
		if (ans[n/2]==0) ans[n/2]=calc(n/2);
		return ans[n/2]+1;
	}
	else
	{
		if (ans[3*n+1]==0) ans[3*n+1]=calc(3*n+1);
		return ans[3*n+1]+1;
	}
}

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
	long i,m,f,t;
	memset(ans,0,sizeof(ans));
	ans[1]=1;
	for (i=2;i<=1000;i++)
		ans[i]=calc(i);
	while (scanf("%d%d",&f,&t)!=EOF)
	{
		m=0;
		if (f<=t)
		{
		for (i=f;i<=t;i++)
			m=mx(m,ans[i]);
		}
		else
		{
		for (i=t;i<=f;i++)
			m=mx(m,ans[i]);
		}
		printf("%d %d %d\n",f,t,m);
	}
	return 0;
}
	
