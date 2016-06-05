#include <stdio.h>
#include <string.h>

char inp[2000];

int main()
{
	long i,n,m;
	scanf("%s",inp);
	n=strlen(inp);
	if (n==1)
	{
		printf("4\n");
		return 0;
	}
	if (n==2)
	{
		m=0;
		m=(inp[0]-'0')*10+(inp[1]-'0');
		if (m<12)
		{
			printf("8\n");
			return 0;
		}
		if (m<20)
		{
			printf("6\n");
			return 0;
		}
		if (m<40)
		{
			printf("11\n");
			return 0;
		}
		if (m<100)
		{
			printf("31\n");
			return 0;
		}
	}
	m=0;
	m=(inp[0]-'0')*10+(inp[1]-'0');
	if (m<12)
	{
		printf("7");
	}
	else
	{
		if (m<20)
		{
			printf("5");
		}
		else
		{
			if (m<40)
			{
				printf("10");
			}
			else
			{
				if (m<100)
				{
					printf("30");
				}
			}
		}
	}
	for (i=4;i<=n;i++)
	{
		printf("0");
	}
	printf("1\n");
	return 0;
}
