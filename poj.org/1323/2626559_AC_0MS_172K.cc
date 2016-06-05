#include <stdio.h>
#include <string.h>

bool pips[1024];

int main()
{
	int n, m;
	int ti = 0;
	while (scanf("%d%d", &m, &n), n > 0)
	{
		int i, pip, ans;
		memset(pips, false, sizeof(pips));
		ans = 0;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &pip);
			pips[pip] = true;
		}
		m *= n;
		pip = 0;
		for (i = m; i >= 1; --i)
		{
			if (pips[i])
			{
				if (pip == 0)
				{
					++ans;
				}
				else
				{
					--pip;
				}
			}
			else
			{
				++pip;
			}
		}
		printf("Case %d: %d\n", ++ti, ans);
	}
	return 0;
}
