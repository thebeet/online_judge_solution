#include <stdio.h>

long s[10000001];

int main()
{
	long p1,p2,ss1,ss2,n;
	s[0]=1;
	s[1]=1;
	p1=1;p2=1;
	ss1=3;ss2=4;
	while (s[0]<10000000)
		if (ss1<ss2)
		{
			s[0]++;
			s[s[0]]=ss1;
			p1++;
			ss1=s[p1]+s[p1]+1;
		}
		else
		{
			if (ss1>ss2)
			{
				s[0]++;
				s[s[0]]=ss2;
				p2++;
				ss2=s[p2]+s[p2]+s[p2]+1;
			}
			else
			{
				s[0]++;
				s[s[0]]=ss1;
				p1++;
				ss1=s[p1]+s[p1]+1;
				p2++;
				ss2=s[p2]+s[p2]+s[p2]+1;
			}
		}
	while (scanf("%d",&n)==1)
		printf("%d\n",s[n]);
	return 0;
}

	