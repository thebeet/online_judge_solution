#include <stdio.h>
#include <memory.h>

unsigned __int64 c[30];

int main()
{
	unsigned __int64 i,m,k,l,t,s,d,ans;
	memset(c,0,sizeof(c));
	for (i=1;i<=19;i++)
	{
		c[i]=c[i-1]*10+1;
	}
	scanf("%I64u%I64u",&k,&m);
	t=k;
	l=1;
	s=0;
	d=1;
	while (t>=10)
	{
		s+=(t%10)*c[l];
		d=d*10;
		t/=10;
		l++;
	}
	ans=k;
	s+=((t-1)*c[l]+l);
	d=k-d;
	if (s>m)
	{
		printf("0\n");
		return 0;
	}
	if ((d==0) && (s<m))
	{
		printf("0\n");
		return 0;
	}
	while (s<m)
	{
		ans*=10;
		d*=10;
		s+=d;
	}
	if (s==m)
	{
		printf("%I64u\n",ans);
		return 0;
	}
	else
	{
		ans=ans-(s-m+1);
	}
	printf("%I64u\n",ans);
	return 0;
}
