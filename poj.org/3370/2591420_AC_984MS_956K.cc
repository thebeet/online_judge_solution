#include <cstdio>
#include <cstring>

int tmod[100010];
int inp[100010];

int main()
{
	int c, n;
	while (scanf("%d%d", &c, &n), c > 0)
	{
		int i, j;
		int sum = 0;
		memset(tmod, 10, sizeof(tmod));
		tmod[0] = 0;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &inp[i]);
			sum = (sum + inp[i]) % c;
			if (tmod[sum] < n)
			{
				for (j = tmod[sum] + 1; j <= i; ++j)
				{
					printf("%d%c", j, ((j == i) ? '\n' : ' '));
				}
				break;
			}
			tmod[sum] = i;
		}
		for ( ++i; i <= n; ++i)
		{
			scanf("%*d");
		}
	}
	return 0;
}
