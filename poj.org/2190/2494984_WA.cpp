#include <stdio.h>
#include <string.h>

int main()
{
	char inp[256];
	int sum = 0;
	int x;
	int i;
	scanf("%s", inp);
	for (i = 0; i < 10; ++i)
	{
		int t;
		if (inp[i] == 'X')
		{
			t = 10;
		}
		else
		{
			t = inp[i] - '0';
		}
		if (inp[i] == '?')
		{
			x = 10 - i;
		}
		else
		{
			sum += (10 - i) * t;
		}
	}
	for (i = 0; i <= 10; ++i)
	{
		if ((((i * x) + sum) % 11) == 0)
		{
			break;
		}
	}
	if (i > 10)
	{
		printf("-1\n");
	}
	else
	{
		char oup;
		if (i == 10)
		{
			oup = 'X';
		}
		else
		{
			oup = '0' + i;
		}
		printf("%c\n", oup);
	}
	return 0;
}
