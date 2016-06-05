#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, bool> up[128];
map<int, bool> down[128];


int main()
{
	int i, j, n, m;
	cin >> n >> m;
	for (i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		for (map<int, bool>::iterator i = up[a].begin(); i != up[a].end(); ++i)
		{
			up[b][i->first] = true;
			down[i->first][b] = true;
		}
		up[b][a] = true;
		for (map<int, bool>::iterator i = down[b].begin(); i != down[b].end(); ++i)
		{
			down[a][i->first] = true;
			up[i->first][b] = true;
		}
		down[a][b] = true;
	}
	int ans(0);
	for (i = 1; i <= n; ++i)
	{
		if (down[i].size() + up[i].size() == n - 1)
		{
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
