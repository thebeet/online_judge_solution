#include <stdio.h>
#include <memory.h>

#define MAXN 80010

int height[MAXN];
int sight[MAXN];
long long ans[MAXN];

int main()
{
	int i, n, ts;
	long long total;
	
	while (scanf("%d", &n) != EOF)
	{
		memset(height, 0, sizeof(height));
		memset(sight, 0, sizeof(sight));
		memset(ans, 0, sizeof(ans));
		total = 0;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &height[i]);
		}
		sight[n] = n + 1;
		height[n + 1] = 2100000000;
		for (i = n - 1; i >= 1; --i)
		{
			ts = i + 1;
			while (height[i] > height[ts])
			{
				ans[i] += ans[ts] + 1;
				ts = sight[ts];
			}
			sight[i] = ts;
			total += ans[i];
		}
		printf("%I64d\n", total);
	}
	return 0;
}
