#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> up[128];
set<int> down[128];

int main()
{
	int i, j, n, m;
	cin >> n >> m;
	for (i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		for (set<int>::iterator i = up[a].begin(); i != up[a].end(); ++i)
		{
			up[b].insert(*i);
		}
		up[b].insert(a);
		for (set<int>::iterator i = down[b].begin(); i != down[b].end(); ++i)
		{
			down[a].insert(*i);
		}
		down[a].insert(b);
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
