#include <stdio.h>
#include <algorithm>

using std::max;

const int MAXN = 100010;

int dp[MAXN];
int nums[MAXN];

int main()
{
	int i, n, dp2, s, ans;
	while (scanf("%d", &n), n > 0)
	{
		ans = -2000000000;
		s = 0;
		dp[0] = -2000000000; 
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &nums[i]);
			s += nums[i];
			dp[i] = max(dp[i - 1], s);
			if (s < 0)
			{
				s = 0;
			}
		}
		s = 0;
		dp2 = -2000000000;
		for (i = n; i >= 2; --i)
		{
			s += nums[i];
			dp2 = max(dp2, s);
			if (s < 0)
			{
				s = 0;
			}
			ans = max(ans, dp2 + dp[i - 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
