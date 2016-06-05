#include <stdio.h>
#include <string.h>

bool usage[10010];

int main()
{
	int i, n, k, s, m;
	int deg = 0;
	int ans = 1;
	scanf("%d%d", &n, &k);
	s = k + 1;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		if (usage[m] == false)
		{
			usage[m] = true;
			if (++deg == k)
			{
				deg = 0;
				++ans;
				memset(usage, false, s);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
