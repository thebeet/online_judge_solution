#include <stdio.h>
#include <memory.h>

#define MAXN 100000

int gone[100010];

int main()
{
	int i, n, k, t;
	memset(gone, 0, sizeof(gone));
	
	scanf("%d%d", &n, &k);
	
	t = 0;
	gone[n] = 1;
	while (gone[k] == 0)
	{
		++t;
		for (i = 1; i <= MAXN; ++i)
		{ 
			if (gone[i] == t)
			{
				if (((i - 1) > 0) && (gone[i - 1] == 0))
				{
					gone[i - 1] = t + 1;
				}
				if (((i + 1) <= MAXN) && (gone[i + 1] == 0))
				{
					gone[i + 1] = t + 1;
				}
				if (((i << 1) <= MAXN) && (gone[i << 1] == 0))
				{
					gone[i << 1] = t + 1;
				}
			}
		}
	}
	printf("%d\n", gone[k] - 1);
	return 0;
}
