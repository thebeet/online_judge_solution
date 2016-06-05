#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair< pair<int, int>, int> path;
path paths[10010];

bool operator < (const path &p1, const path &p2)
{
	return (p1.second < p2.second);
}

int father[1024];

int setfind(const int p)
{
	if (father[p] != p)
	{
		father[p] = setfind(father[p]);
	}
	return father[p];
}

int main()
{
	int i, j, n, p, k;
	scanf("%d%d%d", &n, &p, &k);
	for (i = 1; i <= n; ++i)
	{
		father[i] = i;
	}
	for (i = 0; i < p; ++i)
	{
		scanf("%d%d%d", &paths[i].first.first, &paths[i].first.second, &paths[i].second);
	}
	sort(paths, paths + p);
	int connect(0);
	int ans(0);
	for (i = 0; i < p; ++i)
	{
		int f1 = setfind(paths[i].first.first);
		int f2 = setfind(paths[i].first.second);
		if (f1 != f2)
		{
			++connect;
			if (connect + k + 1 == n)
			{
				ans = paths[i].second;
			}
			father[f1] = f2;
		}
	}
	if (connect == n - 1)
	{
		cout << ans << endl;
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
