#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m;
		int ans1, ans2;
		ans1 = 0;
		ans2 = 0;
		
		scanf("%d%d", &m, &n);
		for (i = 1; i <= n; ++i)
		{
			int p;
			scanf("%d", &p);
			ans1 = max(ans1, min(p, m - p));
			ans2 = max(ans2, max(p, m - p));
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
