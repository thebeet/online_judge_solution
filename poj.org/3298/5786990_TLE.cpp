#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[30010][2];
int arr[30010];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		scanf("%d", &arr[0]);
		dp[0][0] = 1;
		int ans(1);
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			for (int j = 0; j < i; ++j)
			{
				if ((dp[j][0] >= 0) && (arr[j] > arr[i]))
				{
					ans = max(ans, dp[i][1] = max(dp[i][1], dp[j][0] + 1));
				}
				if ((dp[j][1] >= 0) && (arr[j] < arr[i]))
				{
					ans = max(ans, dp[i][0] = max(dp[i][0], dp[j][1] + 1));
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
