#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> path[10010];

void dfs(const int p)
{
	printf("%d\n", p);
	while (path[p].size() > 0)
	{
		map<int, int>::iterator it = path[p].begin();
		int nextp = it->first;
		
		if ((--(it->second)) == 0)
		{
			path[p].erase(it);
		}
		it = path[nextp].find(p);
		if ((--(it->second)) == 0)
		{
			path[nextp].erase(it);
		}
		dfs(nextp);
		printf("%d\n", p);
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		++path[a][b];
		++path[b][a];
	}
	dfs(1);
	return 0;
}

