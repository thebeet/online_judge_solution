#include <stdio.h>

bool check(long n)
{
	long m;
	m=n%10;
	n/=10;
	m+=(n%10);
	n/=10;
	m+=(n%10);
	n/=10;
	m-=(n%10);
	n/=10;
	m-=(n%10);
	n/=10;
	m-=(n%10);
	if (m==0) return true;
	else return false;
}

int main()
{
	long n;
	scanf("%d",&n);
	if ((n==0) || (n==999999))
	{
		printf("No\n");
	}
	else
	{
		n--;
		if (check(n)) printf("Yes\n");
		else
		{
			n+=2;
			if (check(n)) printf("Yes\n");
			else
			{
				printf("No\n");
			}
		}
	}
	return 0;
}
