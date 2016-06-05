#include <stdio.h>

#define p 11915417
#define r 8340792
#define MAXN 10011

char c[MAXN];
__int64 tm[MAXN];
__int64 n,l,h,s1,s2;

bool check()
{
	__int64 i;
	for (i=1;i<=l;i++)
		if (c[h+i-1]!=c[n-i+1])
			return false;
	return true;
}
	

int main()
{
	__int64 i;
	bool flag;
	n=1;
	scanf("%c",&c[n]);
	while (c[n]>20)
	{
		n++;
		scanf("%c",&c[n]);
	}
	n--;
	if ((n&1)==0) flag=true;
	else flag=false;
	l=n/2;
	h=1;
	s1=0;
	s2=0;
	tm[0]=1;
	for (i=1;i<=l;i++)
	{
		s1=(s1*10+c[i])%p;
		s2=(s2*10+c[n-i+1])%p;
		tm[i]=(tm[i-1]*10)%p;
	}
	while (true)
	{
		if (flag)
		{
			l--;
			s1=(s1-tm[l]*c[h]+p)%p;
			s2=((s2-c[n-l]+p)*r)%p;
			flag=false;
			h++;
		}
		else
		{
			s1=((s1-tm[l-1]*c[h])*10+c[n-l]+p)%p;
			h++;
			flag=true;
		}
		if ((s1==s2) || (check())) break;
	}
	for (i=1;i<=n;i++)
		printf("%c",c[i]);
	for (i=h-1;i>0;i--)
		printf("%c",c[i]);
	printf("\n");
	return 0;
}



