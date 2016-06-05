#include <iostream>
#include <algorithm>

using namespace std;

int head[65536];
int kingdom[65536];

int main()
{
	int i, n, m;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &head[i]);
		}
		for (i = 0; i < m; ++i)
		{
			scanf("%d", &kingdom[i]);
		}
		sort(head, head + n);
		sort(kingdom, kingdom + m);
		int j(0);
		int ans(0);
		for (i = 0; ((i < n) && (j < m)); ++i, ++j)
		{
			while ((j < m) && (head[i] > kingdom[j])) ++j;
			if (j == m) break;
			ans += kingdom[j];
		}
		if (i == n)
		{
			cout << ans << endl;
		}
		else
		{
			cout << "Loowater is doomed!" << endl;
		}
	}
	return 0;
}
