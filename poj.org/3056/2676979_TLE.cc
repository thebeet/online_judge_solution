#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[1024][1024];
int pro[1024];

int calc(int st, int ed)
{
	if (st > ed)
	{
		return 0;
	}
	else
	{
		if (ans[st][ed] >= 1024)
		{
			int i;
			if (pro[st] == pro[st + 1])
			{
				ans[st][ed] = 1 + calc(st + 2, ed);
			}
			else if (pro[st] == pro[ed])
			{
				ans[st][ed] = 1 + calc(st + 1, ed - 1);
			}
			else
			{
				ans[st][ed] = 0;
				for (i = st + 3; i <= ed; i += 2)
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
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, k, j;
		
		memset(ans, 1, sizeof(ans));
		
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &pro[i]);
		}
		printf("%d\n", calc(1, n));
	}
	return 0;
}
