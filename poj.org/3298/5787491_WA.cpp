#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[2][30010];
int arr[30010];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		memset(dp, 128, sizeof(dp));
		int total[2];
		total[0] = total[1] = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			int changehi[2];
			for (int k = 0; k < 2; ++k)
			{
				int lo(0);
				int hi(total[k] + 1);
				while (lo + 1 < hi)
				{
					int mid((lo + hi) >> 1);
					if (k == 0)
					{
						((dp[k][mid] > arr[i]) ? lo : hi) = mid;
					}
					else
					{
						((dp[k][mid] < arr[i]) ? lo : hi) = mid;
					}
				}
				changehi[k ^ 1] = hi;
			}
			for (int k = 0; k < 2; ++k)
			{
				int hi = changehi[k];
				if (k == 1)
				{
					if (dp[k][hi - k] < 0)
					{
						dp[k][hi - k] = arr[i];
					}
					else
					{
						dp[k][hi - k] = min(dp[k][hi - k], arr[i]);
					}
				}
				else
				{
					if (dp[k][hi - k] < 0)
					{
						dp[k][hi - k] = arr[i];
					}
					else
					{
						dp[k][hi - k] = max(dp[k][hi - k], arr[i]);
					}
				}
				if (total[k] < (hi - k))
				{
					total[k] = (hi - k);
				}
			}
		}
		printf("%d\n", total[0] + total[1]);
	}
	return 0;
}
