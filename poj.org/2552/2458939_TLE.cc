#include <stdio.h>
#include <string.h>

int lucky[100010];

int main()
{
	int i, j, k, n;
	memset(lucky, 0, sizeof(lucky));
	for (i = 2; i <= 100000; ++i)
	{
		if (lucky[i] == 0)
		{
			lucky[++lucky[0]] = i;
			k = i;
			for (j = i + 1; j <= 100000; ++j)
			{
				if (lucky[j] == 0)
				{
					--k;
					if (k == 0)
					{
						lucky[j] = 1;
						k = i;
					}
				}
			}
		}
	}
	while (scanf("%d", &n), n > 0)
	{
		printf("%d\n", lucky[n]);
	}
	return 0;
}
