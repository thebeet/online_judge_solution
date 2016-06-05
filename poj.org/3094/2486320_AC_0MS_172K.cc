#include <stdio.h>
#include <string.h>

char inp[300];

int main()
{
	while (gets(inp + 1), inp[1] != '#')
	{
		int ans = 0;
		for (int i = 1; i <= strlen(inp + 1); ++i)
		{
			if (inp[i] >= 'A')
			{
				ans += (inp[i] - 'A' + 1) * i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
