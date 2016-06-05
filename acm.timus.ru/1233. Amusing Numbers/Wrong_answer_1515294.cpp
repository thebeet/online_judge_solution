#include <stdio.h>
#include <memory.h>

long long c[30];

int main()
{
	long long i,m,k,l,t,s,d,ans;
	memset(c,0,sizeof(c));
	for (i=1;i<=18;i++)
	{
		c[i]=c[i-1]*10+1;
	}
	scanf("%lld%lld",&k,&m);
	t=k;
	l=1;
	s=0;
	d=0;
	while (t>=10)
	{
		s+=(t%10)*c[l];
		d+=(t%10);
		t/=10;
		l++;
	}
	ans=k;
	s+=((t-1)*c[l]+1);
	d+=(t-1);
	if (s>m)
	{
		printf("0\n");
		return 0;
	}
	if ((s==1) && (s<m))
	{
		printf("0\n");
		return 0;
	}
	t=0;
	while (s<m)
	{
		ans*=10;
		t++;
		s=(s-1)*10+d+1;
	}
	ans=ans-(s-m+t);
	printf("%lld\n",ans);
	return 0;
}
