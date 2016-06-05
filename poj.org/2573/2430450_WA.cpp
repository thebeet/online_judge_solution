#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int costtime[1010];
int ans[10010];

int calc()
{
	switch (costtime[0])
	{
		case 1:
		{
			ans[++ans[0]] = costtime[1];
			return costtime[1];
		}
		case 2:
		{
			ans[++ans[0]] = costtime[1];
			ans[++ans[0]] = costtime[2];
			return costtime[2];
		}
		case 3:
		{
			ans[++ans[0]] = costtime[1];
			ans[++ans[0]] = costtime[2];
			ans[++ans[0]] = costtime[1];
			ans[++ans[0]] = costtime[1];
			ans[++ans[0]] = costtime[3];
			ans[++ans[0]] = costtime[1];
			return costtime[1] + costtime[2] + costtime[3];
		}
		default:
		{
			if (costtime[2] + costtime[2] > costtime[1] + costtime[costtime[0] - 1])
			{
				int sum;
		
				ans[++ans[0]] = costtime[costtime[0]];
				ans[++ans[0]] = costtime[1];
				ans[++ans[0]] = costtime[1];
				ans[++ans[0]] = costtime[costtime[0] - 1];
				ans[++ans[0]] = costtime[1];
				ans[++ans[0]] = costtime[1];
				sum = costtime[costtime[0]] + costtime[costtime[0] - 1] + costtime[1] + costtime[1];
				costtime[0] -= 2;
				return sum + calc();
			}
			else
			{
				int sum;
		
				ans[++ans[0]] = costtime[1];
				ans[++ans[0]] = costtime[2];
				ans[++ans[0]] = costtime[1];
				ans[++ans[0]] = costtime[costtime[0]];
				ans[++ans[0]] = costtime[costtime[0] - 1];
				ans[++ans[0]] = costtime[2];
				sum = costtime[costtime[0]] + costtime[1] + costtime[2] + costtime[2];
				costtime[0] -= 2;
				return sum + calc();
			}
		}
	}
	return 0;
}

int main()
{
	int i, n;
	memset(ans, 0, sizeof(ans));
	memset(costtime, 0, sizeof(costtime));
	
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &costtime[i]);
	}
	costtime[0] = n;
	sort(costtime + 1, costtime + 1 + n);
	printf("%d\n", calc());
	if (ans[0] == 1)
	{
		printf("%d\n", ans[1]);
	}
	else
	{
		for (i = 1; i <= ans[0] - 2; i += 3)
		{
			printf("%d %d\n", ans[i], ans[i + 1]);
			printf("%d\n", ans[i + 2]);
		}
		if ((ans[0] % 3) != 0)
		{
			printf("%d %d\n", ans[i], ans[i + 1]);
		}
	}
	return 0;
}
