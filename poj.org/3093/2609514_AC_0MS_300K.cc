#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[32][1024];
int nums[32];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, k, n, v, sum, ans;
		bool flag = false;
		
		sum = 0;
		ans = 0;
		
		scanf("%d%d", &n, &v);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &nums[i]);
			sum += nums[i];
			if (nums[i] <= v)
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			printf("%d 0\n", ti);
			continue;
		}
		sort(nums + 1, nums + 1 + n);
		
		if (sum <= v)
		{
			printf("%d 1\n", ti);
		}
		else
		{
			memset(dp, 0, sizeof(dp));
			dp[1][0] = 1;
			sum = 0;
			for (i = 1; i <= n; ++i)
			{
				if (sum + nums[i] > v)
				{
					sum = v - nums[i];
				}
				for (k = i; k >= 1; --k)
				{
					for (j = sum; j >= 0; --j)
					{
						if (j + nums[i] <= v)
						{
							if (k == i)
							{
								dp[k + 1][j + nums[i]] += dp[k][j];
							}
							else
							{
								dp[k][j + nums[i]] += dp[k][j];
							}
						}
					}
				}
				sum += nums[i];
			}
			ans = 0;
			for (k = 1; k <= n; ++k)
			{
				for (i = 0; i <= v; ++i)
				{
					if (nums[k] + i > v)
					{
						ans += dp[k][i];
					}
				}
			}
			printf("%d %d\n", ti, ans);
		}
	}
	return 0;
}
