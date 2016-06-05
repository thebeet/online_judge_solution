#include <iostream>
#include <algorithm>

using namespace std;

const int step = 64;

char map[128][128];
char b_map[128][128];

int nx[5010];
int ny[5010];

int n, m;

void add(int x, int y)
{
	int i;
	x += step;
	y += step;
	for (i = 0; i < 128; ++i)
	{
		map[i][y] = map[x][i] = '.';
	}
	for (i = -32; i < 32; ++i)
	{
		map[x + i][y + i] = '.'; 
		map[x + i][y - i] = '.'; 
	}
}

int count()
{
	int i, j;
	int ans(0);
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			if (map[i + step][j + step] == 0)
			{
				++ans;
			}
		}
	}
	return ans;
}

int main()
{
	int i, j, k;
	char buf[16];
	cin >> n >> m >> k;
	memset(map, 0, sizeof(map));
	for (i = 1; i <= k; ++i)
	{
		scanf("%s", buf);
		nx[i] = buf[0] - 'a' + 1;
		sscanf(buf + 1, "%d", &ny[i]);
		add(nx[i], ny[i]);
	}
	for (i = 1; i <= k; ++i)
	{
		map[nx[i]][ny[i]] = '*';
	}
	int ansp1, ansp2;
	int mxans = -1;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			if (map[i][j] != '*')
			{
				memcpy(b_map, map, sizeof(map));
				add(i, j);
				int ret = count();
				if (mxans < ret)
				{
					mxans = ret;
					ansp1 = i;
					ansp2 = j;
				}
				memcpy(map, b_map, sizeof(map));
			}
		}
	}
	cout << (char)('a' - 1 + ansp1) << ansp2 << endl;
	cout << mxans << endl;
	return 0;
}
