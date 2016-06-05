#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[1024][1024];
int pro[1024];

int calc(int st, int ed)
{
	if (ans[st][ed] >= 1024)
	{
		int i;
		if (pro[st] == pro[ed])
		{
			ans[st][ed] = 1 + calc(st + 1, ed - 1);
		}
		else
		{
			ans[st][ed] = 0;
			for (i = st + 1; i <= ed; i += 2)
			{
				if (pro[i] == pro[st])
				{
					ans[st][ed] = max(ans[st][ed], 1 + calc(st + 1, i - 1) + calc(i + 1, ed));
				}
				else
				{
					ans[st][ed] = max(ans[st][ed], calc(st + 1, i - 1) + calc(i + 1, ed));
				}
			}
		}
	}
	return ans[st][ed];
}

int main()
{
	int ti, tn;
	//freopen("inp.txt", "r", stdin);
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, n, k, tans;
		
		scanf("%d", &n);
		tans = 0;
		memset(pro, 0, sizeof(pro));
		k = 0;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &pro[++k]);
			if (pro[k] == pro[k - 1])
			{
				k -= 2;
				++tans;
			}
		}
		pro[k + 1] = 0;
		pro[k + 2] = 0;
		
		memset(ans, 0, sizeof(ans));

		for (i = 1; i <= k; ++i)
		{
			for (j = 1; j <= k; ++j)
			{
				ans[i][j] = (i >= j) ? 0 : 2048;
			}
		}

		printf("%d\n", tans + calc(1, k));
	}
	return 0;
}
