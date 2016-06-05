#include <stdio.h>
#include <string.h>

char a[1010],b[1010],c[1010];
long s1[1010],s2[1010];
long dp[2][1010];
long la,lb,lc,lab,minab;

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

long mn(long a,long b)
{
	if (a>b) return b;
	else return a;
}

long abs(long n)
{
	if (n<0) return (-n);
	else return n;
}

int main()
{
	long i,s;
	s=0;
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	la=strlen(a);
	lb=strlen(b);
	lc=strlen(c);
	lab=mx(la,lb);
	minab=mn(la,lb);
	if (lc<lab)
	{
		printf("-1\n");
		return 0;
	}
	if ((lc>lab+1))
	{
		printf("-1\n");
		return 0;
	}
	memset(s1,0,sizeof(s1));
	s1[0]=lab;
	for (i=1;i<=lab;i++)
	{
		if (la>=i) s1[i]+=(a[la-i]-48);
		if (lb>=i) s1[i]+=(b[lb-i]-48);
	}
	s2[0]=lc;
	for (i=1;i<=lc;i++)
	{
		s2[i]=c[lc-i]-48;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=0;
	dp[1][0]=100000;
	for (i=1;i<=minab;i++)
	{
		dp[0][i]=mn(abs(s1[i]- s2[i]+1)+dp[1][i-1],abs(s1[i]- s2[i])+dp[0][i-1]);
		dp[1][i]=mn(abs(s1[i]-10- s2[i]+1)+dp[1][i-1],abs(s1[i]-10- s2[i])+dp[0][i-1]);
	}
	if (s2[0]>s1[0])
	{
		for (i=lab;i>=minab+1;i--)
		{
			s+=(abs(9- s1[i])+abs(s2[i]));
		}
		s+=abs(s2[s2[0]]-1);
		s+=dp[1][minab];
		printf("%ld\n",s);
	}
	else
	{
		if (minab<lab)
		{
			for (i=lab;i>=minab+2;i--)
			{
				s+=abs(s1[i]- s2[i]);
			}
			s=mn(s+abs(s1[minab+1]- s2[minab+1])+dp[0][minab],s+abs(s1[minab+1]- s2[minab+1]+1)+dp[1][minab]);
			printf("%ld\n",s);
		}
		else
		{
			printf("%ld\n",dp[0][minab]);
		}
	}
	return 0;
}
