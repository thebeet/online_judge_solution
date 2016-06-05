#include <cstdio>
#include <cstring>

int number[1048576];
char inp[1048576];

int main()
{
	int ti(0);
	for (;;)
	{
		gets(inp);
		int t = strlen(inp);
		if ((t == 1) && (inp[0] == '0'))
		{
			return 0;
		}
		printf("%d. ", ++ti);
		int i;
		number[t] = 0;
		for (i = t - 1; i >= 0; --i)
		{
			number[i] = inp[i] - '0';
			number[i] -= number[i + 1];
			if (number[i] < 0)
			{
				number[i] += 10;
				if (i > 0)
				{
					--inp[i - 1];
				}
			}
			inp[i] = '0' + number[i];
		}
		if (number[0] > 0)
		{
			printf("%s\n", inp);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
