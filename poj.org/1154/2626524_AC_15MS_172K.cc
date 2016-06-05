#include <stdio.h>
#include <string.h>
#include <algorithm>

using std::max;

char map[32][32];
bool gone[256];

int dfs(int x, int y)
{
	if (gone[(int)map[x][y]])
	{
		return 0;
	}
	else
	{
		gone[(int)map[x][y]] = true;
		int ans = max(max(dfs(x + 1, y), dfs(x - 1, y)), max(dfs(x, y + 1), dfs(x, y - 1))) + 1;
		gone[(int)map[x][y]] = false;
		return ans;
	}
}

int main()
{
	int i, n;
	scanf("%d%*d", &n);
	memset(map, 0, sizeof(map));
	for (i = 1; i <= n; ++i)
	{
		scanf("%s", map[i] + 1);
	}

	memset(gone, false, sizeof(gone));
	gone[0] = true;
	printf("%d\n", dfs(1, 1));
	return 0;
}

