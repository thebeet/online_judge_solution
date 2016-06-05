#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int c[256][256];
int f[256][256];
int cf[256][256];

int pre[256];


int n;

int bfs(const int st, const int ed)
{
	bool gone[256];
	memset(gone, false, sizeof(gone));
	queue<int> q;
	gone[st] = true;
	q.push(st);
	while (q.empty() == false)
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i)
		{
			if ((gone[i] == false) && (cf[now][i] > 0))
			{
				pre[i] = now;
				gone[i] = true;
				q.push(i);
				if (i == ed)
				{
					break;
				}
			}
		}
	}
	if (gone[ed] == false)
	{
		return 0;
	}
	int mx(100000000);
	for (int p = ed; p != st; p = pre[p])
	{
		mx = std::min(mx, cf[pre[p]][p]);
	}
	for (int p = ed; p != st; p = pre[p])
	{
		cf[pre[p]][p] -= mx;
		cf[p][pre[p]] += mx;
	}
	return mx;
}

int main()
{
	int m;
	while (cin >> m >> n)
{
memset(c,0,sizeof(c));
memset(cf,0,sizeof(cf));
memset(f,0,sizeof(f));
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		c[x][y] += z;
		cf[x][y] = c[x][y] - f[x][y];
	}
	int ans(0);
	int ret;
	while ((ret = bfs(1, n)), ret != 0)
	{
		ans += ret;
	}
	cout << ans << endl;
}
	return 0;
}