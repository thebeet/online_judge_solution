#include <stdio.h>
#include <string.h>

int main()
{
	int ti, s, t, m, ans;
	ti = 0;
	while (scanf("%d%d%d", &s, &t, &m), s > 0)
	{
		int sid, b, c, l;
		int team[110];
		memset(team, 0, sizeof(team));
		++ti;
		ans = 0;
		for (int i = 1; i <= s; ++i)
		{
			scanf("%*d%d%d", &b, &c);
			ans += (b + c);
		}
		for (int i = 1; i <= t; ++i)
		{
			scanf("%d%d", &sid, &l);
			if (l >= m)
			{
				team[sid] = 1;
			}
		}
		for (int i = 1; i <= s; ++i)
		{
			ans += team[i];
		}
		printf("Case %d: %d\n", ti, ans);
	}
	return 0;
}
