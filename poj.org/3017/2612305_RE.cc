#include <stdio.h>
#include <algorithm>

using std::max;
using std::min;

const int step = 131072;

int nums[step * 2];
long long dp[step];

int rmq(int pst, int ped)
{
	int ans = 0;
	pst += step;
	ped += step;
	while (pst <= ped)
	{
		ans = max(ans, max(nums[pst], nums[ped]));
		pst = (pst + 1) >> 1;
		ped = (ped - 1) >> 1;
	}
	return ans;
}

int main()
{
	int i, n;
	long long m;
	scanf("%d%I64d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &nums[i + step]);
		if ((long long)nums[i + step] > m)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (i = step - 1; i >= 1; --i)
	{
		nums[i] = max(nums[i << 1], nums[(i << 1) + 1]);
	}
	int p1 = 1;
	int p2 = 0;
	long long s = (long long)nums[step + 1];
	dp[0] = 0;
	dp[1] = s;
	for ( ; ;)
	{
		while (s <= m)
		{
			s += (long long)nums[step + (++p1)];
			dp[p1] = (long long)rmq(p2 + 1, p1) + dp[p2];
			if (p1 == n)
			{
				break;
			}
		}
		if (p1 == n)
		{
			break;
		}
		s -= (long long)nums[step + (++p2)];
		dp[p1] = rmq(p2 + 1, p1) + dp[p2];
		while (s >= m)
		{
			s -= (long long)nums[step + (++p2)];
			dp[p1] = min(dp[p1], (long long)rmq(p2 + 1, p1) + dp[p2]);
		}
	}
	for ( ; p2 < n; )
	{
		s -= (long long)nums[step + (++p2)];
		dp[p1] = min(dp[p1], (long long)rmq(p2 + 1, p1) + dp[p2]);
	}
	printf("%I64d\n", dp[n]);
	return 0;
}
