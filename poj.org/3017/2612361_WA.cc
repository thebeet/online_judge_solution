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
	if (n == 1)
	{
		printf("%I64d\n", s);
		return 0;
	}
	for ( ; p1 < n ; )
	{
		s += (long long)nums[step + (++p1)];
		while ((s <= m) && (p1 < n))
		{
			dp[p1] = (long long)rmq(p2 + 1, p1) + dp[p2];
			s += (long long)nums[step + (++p1)];
		}
		s -= (long long)nums[step + (++p2)];
		while (s > m)
		{
			s -= (long long)nums[step + (++p2)];
		}
		dp[p1] = (long long)rmq(p2 + 1, p1) + dp[p2];
	}
	while (p2 < n)
	{
		s -= (long long)nums[step + (++p2)];
		dp[n] = min(dp[n], (long long)rmq(p2 + 1, p1) + dp[p2]);
	}
	printf("%I64d\n", dp[n]);
	return 0;
}
