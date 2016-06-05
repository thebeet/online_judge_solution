#include <stdio.h>
#include <memory.h>

long s[200000];

long mx(long a,long b)
{
	if (a>b) return a;
	else return b;
}

int main()
{
//	freopen("Crack.in","r",stdin);
	long i,n;
	bool st;
	char inp;
	memset(s,0,sizeof(s));
	n=0;
	st=true;
	while (scanf("%c",&inp)!=EOF)
	{
		if (((inp>='A') && (inp<='Z')) || ((inp>='a') && (inp<='z')))
		{
			if (st)
			{
				n++;
				st=false;
			}
			s[n]++;
		}
		else
		{
			st=true;
		}
	}
	if (n==0)
	{
		printf("0\n");
		return 0;
	}
	s[2]=mx(s[1],s[2]);
	for (i=3;i<=n;i++)
		s[i]=mx(s[i-1],mx(s[i-2],s[i-3])+s[i]);
	printf("%ld\n",mx(s[n],s[n-1]));
	return 0;
}
